/* THIS IS AUTO GENERATED CODE */

#ifndef __PIN_H__
#define __PIN_H__

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

/* port A definition */
#define PCB_VER0_PORT		GPIOA
#define PCB_VER0_PIN		GPIO0
#define PCB_VER0_EXTI		EXTI0
#define BOM_VER0_PORT		GPIOA
#define BOM_VER0_PIN		GPIO1
#define BOM_VER0_EXTI		EXTI1
#define MCU_UART1_TX_PORT		GPIOA
#define MCU_UART1_TX_PIN		GPIO2
#define MCU_UART1_TX_EXTI		EXTI2
#define MCU_UART1_RX_PORT		GPIOA
#define MCU_UART1_RX_PIN		GPIO3
#define MCU_UART1_RX_EXTI		EXTI3
#define MCU_INT_PORT		GPIOA
#define MCU_INT_PIN		GPIO4
#define MCU_INT_EXTI		EXTI4
#define CURRENT_IN_PORT		GPIOA
#define CURRENT_IN_PIN		GPIO5
#define CURRENT_IN_EXTI		EXTI5
#define PG_VDD_TPU_PORT		GPIOA
#define PG_VDD_TPU_PIN		GPIO6
#define PG_VDD_TPU_EXTI		EXTI6
#define PG_VDD_TPU_MEM_PORT		GPIOA
#define PG_VDD_TPU_MEM_PIN		GPIO7
#define PG_VDD_TPU_MEM_EXTI		EXTI7
#define PCIEE_RST_MCU_PORT		GPIOA
#define PCIEE_RST_MCU_PIN		GPIO8
#define PCIEE_RST_MCU_EXTI		EXTI8
#define EN_VQPS18_PORT		GPIOA
#define EN_VQPS18_PIN		GPIO9
#define EN_VQPS18_EXTI		EXTI9
#define GPIO1_PORT		GPIOA
#define GPIO1_PIN		GPIO10
#define GPIO1_EXTI		EXTI10
#define P08_PWR_GOOD_PORT		GPIOA
#define P08_PWR_GOOD_PIN		GPIO11
#define P08_PWR_GOOD_EXTI		EXTI11
#define SYS_RST_X_PORT		GPIOA
#define SYS_RST_X_PIN		GPIO12
#define SYS_RST_X_EXTI		EXTI12
#define DDR_PWR_GOOD_PORT		GPIOA
#define DDR_PWR_GOOD_PIN		GPIO15
#define DDR_PWR_GOOD_EXTI		EXTI15

/* port B definition */
#define EN_VDDIO33_PORT		GPIOB
#define EN_VDDIO33_PIN		GPIO0
#define EN_VDDIO33_EXTI		EXTI0
#define EN_VDD_TPU_MEM_PORT		GPIOB
#define EN_VDD_TPU_MEM_PIN		GPIO1
#define EN_VDD_TPU_MEM_EXTI		EXTI1
#define GPIO2_PORT		GPIOB
#define GPIO2_PIN		GPIO2
#define GPIO2_EXTI		EXTI2
#define GPIO3_PORT		GPIOB
#define GPIO3_PIN		GPIO3
#define GPIO3_EXTI		EXTI3
#define EN_VDDIO18_PORT		GPIOB
#define EN_VDDIO18_PIN		GPIO4
#define EN_VDDIO18_EXTI		EXTI4
#define EN_VDD_TPU_PORT		GPIOB
#define EN_VDD_TPU_PIN		GPIO5
#define EN_VDD_TPU_EXTI		EXTI5
#define I2C1_SCL_PORT		GPIOB
#define I2C1_SCL_PIN		GPIO6
#define I2C1_SCL_EXTI		EXTI6
#define I2C1_SDA_PORT		GPIOB
#define I2C1_SDA_PIN		GPIO7
#define I2C1_SDA_EXTI		EXTI7
#define EN_VDDC_PORT		GPIOB
#define EN_VDDC_PIN		GPIO8
#define EN_VDDC_EXTI		EXTI8
#define PMIC_SCL_PORT		GPIOB
#define PMIC_SCL_PIN		GPIO10
#define PMIC_SCL_EXTI		EXTI10
#define PMIC_SDA_PORT		GPIOB
#define PMIC_SDA_PIN		GPIO11
#define PMIC_SDA_EXTI		EXTI11

/* port C definition */
#define MCU_LED_PORT		GPIOC
#define MCU_LED_PIN		GPIO14
#define MCU_LED_EXTI		EXTI14
#define PG_VDDC_PORT		GPIOC
#define PG_VDDC_PIN		GPIO15
#define PG_VDDC_EXTI		EXTI15

void pin_init(void);

#endif
/* AUTO GENERATED CODE END */
