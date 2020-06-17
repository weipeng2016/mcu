/* THIS IS AUTO GENERATED CODE */

#ifndef __PIN_H__
#define __PIN_H__

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

/* port A definition */
#define B6_INPUT_PG4_PORT		GPIOA
#define B6_INPUT_PG4_PIN		GPIO0
#define B6_INPUT_PG4_EXTI		EXTI0
#define B6_INPUT_PG2_3_PORT		GPIOA
#define B6_INPUT_PG2_3_PIN		GPIO1
#define B6_INPUT_PG2_3_EXTI		EXTI1
#define MCU_UART2_TX_PORT		GPIOA
#define MCU_UART2_TX_PIN		GPIO2
#define MCU_UART2_TX_EXTI		EXTI2
#define MCU_UART2_RX_PORT		GPIOA
#define MCU_UART2_RX_PIN		GPIO3
#define MCU_UART2_RX_EXTI		EXTI3
#define B8_INPUT_PG4_PORT		GPIOA
#define B8_INPUT_PG4_PIN		GPIO4
#define B8_INPUT_PG4_EXTI		EXTI4
#define B6_INPUT_PG0_1_PORT		GPIOA
#define B6_INPUT_PG0_1_PIN		GPIO5
#define B6_INPUT_PG0_1_EXTI		EXTI5
#define B5_INPUT_PG0_1_PORT		GPIOA
#define B5_INPUT_PG0_1_PIN		GPIO6
#define B5_INPUT_PG0_1_EXTI		EXTI6
#define B5_INPUT_PG4_PORT		GPIOA
#define B5_INPUT_PG4_PIN		GPIO7
#define B5_INPUT_PG4_EXTI		EXTI7
#define PWR_GOOD_PORT		GPIOA
#define PWR_GOOD_PIN		GPIO8
#define PWR_GOOD_EXTI		EXTI8
#define MCU_UART1_TX_PORT		GPIOA
#define MCU_UART1_TX_PIN		GPIO9
#define MCU_UART1_TX_EXTI		EXTI9
#define MCU_UART1_RX_PORT		GPIOA
#define MCU_UART1_RX_PIN		GPIO10
#define MCU_UART1_RX_EXTI		EXTI10
#define I2C_A0_PORT		GPIOA
#define I2C_A0_PIN		GPIO11
#define I2C_A0_EXTI		EXTI11
#define I2C_A1_PORT		GPIOA
#define I2C_A1_PIN		GPIO12
#define I2C_A1_EXTI		EXTI12
#define MCU_SWDIO_PORT		GPIOA
#define MCU_SWDIO_PIN		GPIO13
#define MCU_SWDIO_EXTI		EXTI13
#define MCU_SWDCLK_PORT		GPIOA
#define MCU_SWDCLK_PIN		GPIO14
#define MCU_SWDCLK_EXTI		EXTI14
#define B2_SYS_RST_N_PORT		GPIOA
#define B2_SYS_RST_N_PIN		GPIO15
#define B2_SYS_RST_N_EXTI		EXTI15

/* port B definition */
#define B6_SYS_RST_N_PORT		GPIOB
#define B6_SYS_RST_N_PIN		GPIO0
#define B6_SYS_RST_N_EXTI		EXTI0
#define B7_SYS_RST_N_PORT		GPIOB
#define B7_SYS_RST_N_PIN		GPIO1
#define B7_SYS_RST_N_EXTI		EXTI1
#define B4_INPUT_PG0_1_PORT		GPIOB
#define B4_INPUT_PG0_1_PIN		GPIO2
#define B4_INPUT_PG0_1_EXTI		EXTI2
#define B3_INPUT_PG0_1_PORT		GPIOB
#define B3_INPUT_PG0_1_PIN		GPIO3
#define B3_INPUT_PG0_1_EXTI		EXTI3
#define EN_B34_VDD_3_3V_PORT		GPIOB
#define EN_B34_VDD_3_3V_PIN		GPIO4
#define EN_B34_VDD_3_3V_EXTI		EXTI4
#define EN_B34_VQPS_1_8V_PORT		GPIOB
#define EN_B34_VQPS_1_8V_PIN		GPIO5
#define EN_B34_VQPS_1_8V_EXTI		EXTI5
#define EN_B34_VDD_1_8V_PORT		GPIOB
#define EN_B34_VDD_1_8V_PIN		GPIO6
#define EN_B34_VDD_1_8V_EXTI		EXTI6
#define B2_INPUT_PG2_3_PORT		GPIOB
#define B2_INPUT_PG2_3_PIN		GPIO7
#define B2_INPUT_PG2_3_EXTI		EXTI7
#define MCU_IIC1_SCL_PORT		GPIOB
#define MCU_IIC1_SCL_PIN		GPIO8
#define MCU_IIC1_SCL_EXTI		EXTI8
#define MCU_IIC1_SDA_PORT		GPIOB
#define MCU_IIC1_SDA_PIN		GPIO9
#define MCU_IIC1_SDA_EXTI		EXTI9
#define MCU_IIC2_SCL_PORT		GPIOB
#define MCU_IIC2_SCL_PIN		GPIO10
#define MCU_IIC2_SCL_EXTI		EXTI10
#define MCU_IIC2_SDA_PORT		GPIOB
#define MCU_IIC2_SDA_PIN		GPIO11
#define MCU_IIC2_SDA_EXTI		EXTI11
#define EN_B56_VDD_TPU_PORT		GPIOB
#define EN_B56_VDD_TPU_PIN		GPIO12
#define EN_B56_VDD_TPU_EXTI		EXTI12
#define EN_B56_VDDC_PORT		GPIOB
#define EN_B56_VDDC_PIN		GPIO13
#define EN_B56_VDDC_EXTI		EXTI13
#define EN_B56_VDD_3_3V_PORT		GPIOB
#define EN_B56_VDD_3_3V_PIN		GPIO14
#define EN_B56_VDD_3_3V_EXTI		EXTI14
#define EN_B56_VDD_1_8V_PORT		GPIOB
#define EN_B56_VDD_1_8V_PIN		GPIO15
#define EN_B56_VDD_1_8V_EXTI		EXTI15

/* port C definition */
#define MCU_IIC3_SCL_PORT		GPIOC
#define MCU_IIC3_SCL_PIN		GPIO0
#define MCU_IIC3_SCL_EXTI		EXTI0
#define MCU_IIC3_SDA_PORT		GPIOC
#define MCU_IIC3_SDA_PIN		GPIO1
#define MCU_IIC3_SDA_EXTI		EXTI1
#define PCIE_RST_X_18_PORT		GPIOC
#define PCIE_RST_X_18_PIN		GPIO2
#define PCIE_RST_X_18_EXTI		EXTI2
#define CURRENT_PCIE_12V_PORT		GPIOC
#define CURRENT_PCIE_12V_PIN		GPIO3
#define CURRENT_PCIE_12V_EXTI		EXTI3
#define B5_SYS_RST_N_PORT		GPIOC
#define B5_SYS_RST_N_PIN		GPIO4
#define B5_SYS_RST_N_EXTI		EXTI4
#define HW_VER_PORT		GPIOC
#define HW_VER_PIN		GPIO5
#define HW_VER_EXTI		EXTI5
#define I2C_A3_PORT		GPIOC
#define I2C_A3_PIN		GPIO6
#define I2C_A3_EXTI		EXTI6
#define B3_SYS_RST_N_PORT		GPIOC
#define B3_SYS_RST_N_PIN		GPIO7
#define B3_SYS_RST_N_EXTI		EXTI7
#define EN_B34_VDD_TPU_PORT		GPIOC
#define EN_B34_VDD_TPU_PIN		GPIO8
#define EN_B34_VDD_TPU_EXTI		EXTI8
#define EN_B34_VDDC_PORT		GPIOC
#define EN_B34_VDDC_PIN		GPIO9
#define EN_B34_VDDC_EXTI		EXTI9
#define EN_B12_VDDC_PORT		GPIOC
#define EN_B12_VDDC_PIN		GPIO10
#define EN_B12_VDDC_EXTI		EXTI10
#define EN_B12_VDD_TPU_PORT		GPIOC
#define EN_B12_VDD_TPU_PIN		GPIO11
#define EN_B12_VDD_TPU_EXTI		EXTI11
#define B3_INPUT_PG2_3_PORT		GPIOC
#define B3_INPUT_PG2_3_PIN		GPIO12
#define B3_INPUT_PG2_3_EXTI		EXTI12
#define EN_B12_VDD_TMEM_PORT		GPIOC
#define EN_B12_VDD_TMEM_PIN		GPIO13
#define EN_B12_VDD_TMEM_EXTI		EXTI13
#define EN_B34_VDD_TMEM_PORT		GPIOC
#define EN_B34_VDD_TMEM_PIN		GPIO14
#define EN_B34_VDD_TMEM_EXTI		EXTI14
#define EN_B78_VDD_TMEM_PORT		GPIOC
#define EN_B78_VDD_TMEM_PIN		GPIO15
#define EN_B78_VDD_TMEM_EXTI		EXTI15

/* port D definition */
#define B1_SYS_RST_N_PORT		GPIOD
#define B1_SYS_RST_N_PIN		GPIO0
#define B1_SYS_RST_N_EXTI		EXTI0
#define B1_INPUT_PG2_3_PORT		GPIOD
#define B1_INPUT_PG2_3_PIN		GPIO1
#define B1_INPUT_PG2_3_EXTI		EXTI1
#define B1_INPUT_PG0_1_PORT		GPIOD
#define B1_INPUT_PG0_1_PIN		GPIO2
#define B1_INPUT_PG0_1_EXTI		EXTI2
#define B1_INPUT_PG4_PORT		GPIOD
#define B1_INPUT_PG4_PIN		GPIO3
#define B1_INPUT_PG4_EXTI		EXTI3
#define B5_INPUT_PG2_3_PORT		GPIOD
#define B5_INPUT_PG2_3_PIN		GPIO4
#define B5_INPUT_PG2_3_EXTI		EXTI4
#define B4_SYS_RST_N_PORT		GPIOD
#define B4_SYS_RST_N_PIN		GPIO5
#define B4_SYS_RST_N_EXTI		EXTI5
#define B3_INPUT_PG4_PORT		GPIOD
#define B3_INPUT_PG4_PIN		GPIO7
#define B3_INPUT_PG4_EXTI		EXTI7
#define EN_B56_VQPS_1_8V_PORT		GPIOD
#define EN_B56_VQPS_1_8V_PIN		GPIO8
#define EN_B56_VQPS_1_8V_EXTI		EXTI8
#define EN_B56_VDD_TMEM_PORT		GPIOD
#define EN_B56_VDD_TMEM_PIN		GPIO9
#define EN_B56_VDD_TMEM_EXTI		EXTI9
#define EN_B78_VDD_TPU_PORT		GPIOD
#define EN_B78_VDD_TPU_PIN		GPIO10
#define EN_B78_VDD_TPU_EXTI		EXTI10
#define EN_B78_VDDC_PORT		GPIOD
#define EN_B78_VDDC_PIN		GPIO11
#define EN_B78_VDDC_EXTI		EXTI11
#define EN_B78_VDD_3_3V_PORT		GPIOD
#define EN_B78_VDD_3_3V_PIN		GPIO12
#define EN_B78_VDD_3_3V_EXTI		EXTI12
#define EN_B78_VDD_1_8V_PORT		GPIOD
#define EN_B78_VDD_1_8V_PIN		GPIO13
#define EN_B78_VDD_1_8V_EXTI		EXTI13
#define EN_B78_VQPS_1_8V_PORT		GPIOD
#define EN_B78_VQPS_1_8V_PIN		GPIO14
#define EN_B78_VQPS_1_8V_EXTI		EXTI14
#define I2C_A4_PORT		GPIOD
#define I2C_A4_PIN		GPIO15
#define I2C_A4_EXTI		EXTI15

/* port E definition */
#define B2_INPUT_PG0_1_PORT		GPIOE
#define B2_INPUT_PG0_1_PIN		GPIO0
#define B2_INPUT_PG0_1_EXTI		EXTI0
#define B2_INPUT_PG4_PORT		GPIOE
#define B2_INPUT_PG4_PIN		GPIO1
#define B2_INPUT_PG4_EXTI		EXTI1
#define MCU_8533_RSTB_PORT		GPIOE
#define MCU_8533_RSTB_PIN		GPIO2
#define MCU_8533_RSTB_EXTI		EXTI2
#define B7_INPUT_PG2_3_PORT		GPIOE
#define B7_INPUT_PG2_3_PIN		GPIO3
#define B7_INPUT_PG2_3_EXTI		EXTI3
#define EN_B12_VDD_3_3V_PORT		GPIOE
#define EN_B12_VDD_3_3V_PIN		GPIO4
#define EN_B12_VDD_3_3V_EXTI		EXTI4
#define EN_B12_VQPS_1_8V_PORT		GPIOE
#define EN_B12_VQPS_1_8V_PIN		GPIO5
#define EN_B12_VQPS_1_8V_EXTI		EXTI5
#define EN_B12_VDD_1_8V_PORT		GPIOE
#define EN_B12_VDD_1_8V_PIN		GPIO6
#define EN_B12_VDD_1_8V_EXTI		EXTI6
#define B4_INPUT_PG4_PORT		GPIOE
#define B4_INPUT_PG4_PIN		GPIO7
#define B4_INPUT_PG4_EXTI		EXTI7
#define MCU_UART4_TX_PORT		GPIOE
#define MCU_UART4_TX_PIN		GPIO8
#define MCU_UART4_TX_EXTI		EXTI8
#define MCU_UART4_RX_PORT		GPIOE
#define MCU_UART4_RX_PIN		GPIO9
#define MCU_UART4_RX_EXTI		EXTI9
#define I2C_A2_PORT		GPIOE
#define I2C_A2_PIN		GPIO10
#define I2C_A2_EXTI		EXTI10
#define B4_INPUT_PG2_3_PORT		GPIOE
#define B4_INPUT_PG2_3_PIN		GPIO11
#define B4_INPUT_PG2_3_EXTI		EXTI11
#define I2C_A5_PORT		GPIOE
#define I2C_A5_PIN		GPIO12
#define I2C_A5_EXTI		EXTI12
#define B8_SYS_RST_N_PORT		GPIOE
#define B8_SYS_RST_N_PIN		GPIO13
#define B8_SYS_RST_N_EXTI		EXTI13
#define B8_INPUT_PG0_1_PORT		GPIOE
#define B8_INPUT_PG0_1_PIN		GPIO14
#define B8_INPUT_PG0_1_EXTI		EXTI14
#define B8_INPUT_PG2_3_PORT		GPIOE
#define B8_INPUT_PG2_3_PIN		GPIO15
#define B8_INPUT_PG2_3_EXTI		EXTI15

/* port H definition */
#define B7_INPUT_PG0_1_PORT		GPIOH
#define B7_INPUT_PG0_1_PIN		GPIO0
#define B7_INPUT_PG0_1_EXTI		EXTI0
#define B7_INPUT_PG4_PORT		GPIOH
#define B7_INPUT_PG4_PIN		GPIO1
#define B7_INPUT_PG4_EXTI		EXTI1
#define P0V9_E_EN_PORT		GPIOH
#define P0V9_E_EN_PIN		GPIO10
#define P0V9_E_EN_EXTI		EXTI10

void pin_init(void);

#endif
/* AUTO GENERATED CODE END */
