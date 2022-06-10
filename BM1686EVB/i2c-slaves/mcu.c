#include <libopencm3/cm3/nvic.h>
#include <i2c_master.h>
#include <string.h>
#include <project.h>
#include <i2c_slave.h>
#include <common.h>
#include <mon.h>
#include <upgrade.h>
#include <loop.h>
#include <chip.h>
#include <eeprom.h>
#include <power.h>
#include <se5.h>
#include <wdt.h>
#include <mcu.h>
#include <ds1307.h>

#define REG_BOARD_TYPE		0x00
#define REG_SW_VER		0x01
#define REG_HW_VER		0x02
#define REG_CMD			0x03
#define REG_BM1686_TMP	0x04
#define REG_BOARD_TMP	0x05
#define REG_INT_STATUS1		0x06
#define REG_INT_STATUS2		0x07
#define REG_INT_MASK1		0x08
#define REG_INT_MASK2 		0x09

//old
#define REG_INT_STATUS		0x06
#define REG_TEST_INTR_EN	0x07
#define REG_INT_MASK		0x08

#define REG_SOC_RST_TIMES	0x0a
#define REG_UPTIME_LO		0x0b
#define REG_UPTIME_HI		0x0c
#define REG_POWEROFF_REASON	0x0d

#define RTC_SECONDS 		0x0e
#define RTC_MINUTES 		0x0f
#define RTC_HOURS			0x10
#define RTC_DATE			0x11
#define RTC_MONTH			0x12
#define RTC_YEAR			0x13

#define I_12V_ATX_L 		0x28

#define BM1686_TMP_OVER_REPORT			1<<0
#define POWER_68127_TMP_OVER_REPORT		1<<1
#define BOARD_TMP_OVER_REPORT			1<<2
#define BOARD_TMP_OVER_POWEROFF			1<<3
#define BM1686_TMP_OVER_POWEROFF		1<<4
#define SYS_POWER_EXCEPTION_POWEROFF	1<<5
#define V12_EXCEPTION_POWEROFF			1<<6
#define BM1686_REBOOT_CMD				1<<7

#define WATCH_DOG 						1<<0
#define TEST_INT						1<<1


#define REG_GP0			0x14
#define REG_DDR			0x15
#define REG_PWR_GOOD		0x16
#define REG_MODE_FLAG		0x17

#define REG_TPU_POWER_CONTROL	0x22	/* tpu power control 0: off 1: on */
#define REG_POWER_LO		0x24
#define REG_POWER_HI		0x25
#define REG_VOLTAGE_LO		0x26
#define REG_VOLTAGE_HI		0x27
#define REG_CURRENT_LO		0x28
#define REG_CURRENT_HI		0x29

#define REG_STAGE		0x3c
#define REG_EEPROM_OFFSET_LO	0x3e	/* 16bit eeprom address, low 8bits */
#define REG_EEPROM_OFFSET_HI	0x3f	/* 16bit eeprom address, high 8bits */
#define REG_EEPROM_DATA		0x40	/* eeprom data */
#define REG_EEPROM_LOCK		0x60	/* eeprom write lock */
#define MCU_REG_MAX		0x64

#define MCU_EEPROM_DATA_MAX	0x20

struct mcu_ctx {
	int set_idx;
	int idx;
	int cmd_tmp;
	uint8_t cmd;
	uint8_t gp0;
	uint8_t int_status[2];
	uint8_t int_mask[2];
	uint8_t eeprom_offset_l, eeprom_offset_h;
	uint16_t tmp;
};


static struct mcu_ctx mcu_ctx;
static struct rtc_time rtc_time;

static const char *tpu_powers[] = {
		"VDD-TPU",
		"ACK-TPU",
		"VDD-TPU-MEM",
		"ACK-TPU_MEM"
};

static void tpu_power_setup(unsigned char enable)
{
	if (enable)
		power_nodes_on(tpu_powers, ARRAY_SIZE(tpu_powers));
	else
		power_nodes_off(tpu_powers, ARRAY_SIZE(tpu_powers));
}

static int tpu_get_power_status(void)
{
	return power_nodes_status(tpu_powers, ARRAY_SIZE(tpu_powers));
}

void mcu_raise_interrupt(uint8_t reg_idx, uint8_t interrupts)
{
	mcu_ctx.int_status[reg_idx] |= interrupts;
	if ((mcu_ctx.int_status[0]&(~mcu_ctx.int_mask[0])) || (mcu_ctx.int_status[1]&(~mcu_ctx.int_mask[1])))
		gpio_set(MCU_INT_PORT, MCU_INT_PIN);
}

void mcu_clear_interrupt(uint8_t reg_idx, uint8_t interrupts)
{
	mcu_ctx.int_status[reg_idx] &= ~interrupts;
	if ((mcu_ctx.int_status[0]&(~mcu_ctx.int_mask[0] == 0)) && (mcu_ctx.int_status[1]&(~mcu_ctx.int_mask[1] == 0)))
		gpio_clear(MCU_INT_PORT, MCU_INT_PIN);
}

void mcu_set_int_mask(uint8_t reg_idx, uint8_t mask)
{
	mcu_ctx.int_mask[reg_idx] = mask;
}

static inline void idx_set(struct mcu_ctx *ctx, uint8_t idx)
{
	ctx->idx = idx % MCU_REG_MAX;
}

static inline void idx_inc(struct mcu_ctx *ctx)
{
	ctx->idx = (ctx->idx + 1) % MCU_REG_MAX;
}

static void mcu_match(void *priv, int dir)
{
	struct mcu_ctx *ctx = priv;

	if (dir == I2C_SLAVE_WRITE)
		ctx->set_idx = 1;
}

#define CMD_POWER_OFF		0x02
#define CMD_RESET		0x03	// drag reset pin
#define CMD_REBOOT		0x07	// power off - power on
#define CMD_UPDATE		0x08

void mcu_process(void)
{
	if (mcu_ctx.cmd == 0)
		return;

	i2c_peripheral_disable(I2C1);
	nvic_disable_irq(NVIC_I2C1_IRQ);
	switch (mcu_ctx.cmd) {
	case CMD_POWER_OFF:
		eeprom_log_power_off_reason(EEPROM_POWER_OFF_REASON_POWER_OFF);
		if (get_board_type() == SM5ME)
			se5_power_off_board();
		else
			power_off();
		wdt_reset();
		break;
	case CMD_RESET:
		eeprom_log_power_off_reason(EEPROM_POWER_OFF_REASON_RESET);
		chip_reset();
		wdt_reset();
		break;
	case CMD_REBOOT:
		eeprom_log_power_off_reason(EEPROM_POWER_OFF_REASON_REBOOT);
		if (get_board_type() == SM5ME)
			se5_reset_board();
		else
			chip_popd_reset();
		wdt_reset();
		break;
	case CMD_UPDATE:
		nvic_enable_irq(NVIC_I2C1_IRQ);
		i2c_upgrade_start();
		break;
	default:
		break;
	}
	mcu_ctx.cmd = 0;
	mcu_ctx.cmd_tmp = 0;
	i2c_peripheral_enable(I2C1);
	nvic_enable_irq(NVIC_I2C1_IRQ);
}

static inline uint16_t eeprom_offset(struct mcu_ctx *ctx)
{
	uint16_t offset_base = ctx->eeprom_offset_l |
		(ctx->eeprom_offset_h << 8);
	uint16_t offset_off =
		ctx->idx - REG_EEPROM_DATA;
	return offset_base + offset_off;
}

static void mcu_write(void *priv, volatile uint8_t data)
{
	struct mcu_ctx *ctx = priv;

	if (ctx->set_idx) {
		idx_set(ctx, data);
		ctx->set_idx = 0;
		return;
	}

	switch (ctx->idx) {
	case REG_CMD:
		ctx->cmd_tmp = data;
		break;
	case REG_INT_STATUS1:
		mcu_clear_interrupt(0, data);
		break;
	case REG_INT_STATUS2:
		if (data & TEST_INT)
			mcu_raise_interrupt(1, TEST_INT);
		break;
	case REG_INT_MASK1:
		mcu_set_int_mask(0, data);
		break;
	case REG_INT_MASK2:
		mcu_set_int_mask(1, data);
		break;
	case REG_GP0:
		ctx->gp0 = data;
		break;
	case REG_EEPROM_OFFSET_LO:
		ctx->eeprom_offset_l = data;
		break;
	case REG_EEPROM_OFFSET_HI:
		ctx->eeprom_offset_h = data;
		break;
	case REG_EEPROM_DATA ...
		(REG_EEPROM_DATA + MCU_EEPROM_DATA_MAX - 1):
		eeprom_write_byte_protected(eeprom_offset(ctx), data);
		break;
	case REG_EEPROM_LOCK:
		eeprom_lock_code(data);
		break;
	case REG_TPU_POWER_CONTROL:
		tpu_power_setup(data);
		break;
	default:
		break;
	}

	idx_inc(ctx);
}

static uint8_t mcu_read(void *priv)
{
	struct mcu_ctx *ctx = priv;
	uint8_t ret = 0;

	switch (ctx->idx) {
	case REG_BOARD_TYPE:
		ret = get_board_type();
		break;
	case REG_SW_VER:
		ret = get_firmware_version();
		break;
	case REG_HW_VER:
		ret = get_hardware_version();
		break;
	case REG_CMD:
		ret = 0;
		break;
	case REG_BM1686_TMP:	
		ret = get_soc_temp();
		break;
	case REG_BOARD_TMP:
		ret = get_ntc_tmp();
		break;
	case REG_INT_STATUS1:
		ret = ctx->int_status[0];
		break;
	case REG_INT_STATUS2:
		ret = ctx->int_status[1];
		break;
	case REG_INT_MASK1:
		ret = ctx->int_mask[0];
		break;
	case REG_INT_MASK2:
		ret = ctx->int_mask[1];
		break;
	case REG_SOC_RST_TIMES:
		ret = chip_reset_times() & 0xff;
		break;
	case REG_UPTIME_LO:
		ctx->tmp = chip_uptime();
		ret = ctx->tmp & 0xff;
		break;
	case REG_UPTIME_HI:
		ret = (ctx->tmp >> 8) & 0xff;
		break;
	case REG_GP0:
		ret = ctx->gp0;
		break;
	case REG_DDR:
		ret = get_ddr_type();
		break;
	case REG_PWR_GOOD:
		ret = 1;
		break;
	case REG_MODE_FLAG:
		ret = get_work_mode();
		break;
	case REG_POWER_LO:
		ctx->tmp = get_current() * 12;
		ret = ctx->tmp & 0xff;
		break;
	case REG_POWER_HI:
		ret = (ctx->tmp >> 8) & 0xff;
		break;
	case REG_CURRENT_LO:
		ctx->tmp = get_current();
		ret = ctx->tmp & 0xff;
		break;
	case REG_CURRENT_HI:
		ret = (ctx->tmp >> 8) & 0xff;
		break;
	case REG_STAGE:
		ret = get_stage();
		break;
	case REG_EEPROM_OFFSET_LO:
		ret = ctx->eeprom_offset_l;
		break;
	case REG_EEPROM_OFFSET_HI:
		ret = ctx->eeprom_offset_h;
		break;
	case REG_EEPROM_DATA ...
		(REG_EEPROM_DATA + MCU_EEPROM_DATA_MAX - 1):
		ret = eeprom_read_byte(eeprom_offset(ctx));
		break;
	case REG_EEPROM_LOCK:
		ret = eeprom_get_lock_status();
		break;
	case REG_TPU_POWER_CONTROL:
		ret = tpu_get_power_status();
		break;
	case RTC_SECONDS:
		get_rtc_time(&rtc_time);
		ret = rtc_time.seconds;
		break;
	case RTC_MINUTES:
		get_rtc_time(&rtc_time);
		ret = rtc_time.minutes;
		break;
	case RTC_HOURS:
		get_rtc_time(&rtc_time);
		ret = rtc_time.hours;
		break;
	case RTC_DATE:
		get_rtc_time(&rtc_time);
		ret = rtc_time.date;
		break;
	case RTC_MONTH:
		get_rtc_time(&rtc_time);
		ret = rtc_time.month;
		break;
	case RTC_YEAR:
		get_rtc_time(&rtc_time);
		ret = rtc_time.year;
		break;
	default:
		ret = 0xff;
		break;
	}

	idx_inc(ctx);
	return ret;
}

static void mcu_stop(void *priv)
{
	struct mcu_ctx *ctx = priv;
	ctx->cmd = ctx->cmd_tmp;
}

static void mcu_reset(void *priv)
{
	struct mcu_ctx *ctx = priv;
	memset(ctx, 0x00, sizeof(*ctx));
}

static struct i2c_slave_op slave = {
	.addr = 0x17,	/* mcu common slave address */
	.mask = 0x00,
	.match = mcu_match,
	.write = mcu_write,
	.read = mcu_read,
	.stop = mcu_stop,
	.reset = mcu_reset,
	.priv = &mcu_ctx,
};

void mcu_init(struct i2c_slave_ctx *i2c_slave_ctx)
{
	loop_add(mcu_process);
	slave.addr = 0x17;
	i2c_slave_register(i2c_slave_ctx, &slave);
}

void mcu_test_init(struct i2c_slave_ctx *i2c_slave_ctx)
{
	slave.addr = 0x38;
	i2c_slave_register(i2c_slave_ctx, &slave);
}

