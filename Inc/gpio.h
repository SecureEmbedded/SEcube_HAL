#ifndef __gpio_H
#define __gpio_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
#include "mcu_ports.h"

/* Pins */
#define PIN0 GPIO_PIN_0
#define PIN1 GPIO_PIN_1
#define PIN2 GPIO_PIN_2
#define PIN3 GPIO_PIN_3
#define PIN4 GPIO_PIN_4
#define PIN5 GPIO_PIN_5
#define PIN6 GPIO_PIN_6
#define PIN7 GPIO_PIN_7
#define PIN8 GPIO_PIN_8
#define PIN9 GPIO_PIN_9
#define PIN10 GPIO_PIN_10
#define PIN11 GPIO_PIN_11
#define PIN12 GPIO_PIN_12
#define PIN13 GPIO_PIN_13
#define PIN14 GPIO_PIN_14
#define PIN15 GPIO_PIN_15

/* SIMPLE MODE */
#define  INPUT 				GPIO_MODE_INPUT
#define  OUT_PUSH_PULL 		GPIO_MODE_OUTPUT_PP
#define  OUT_OPEN_DRAIN 	GPIO_MODE_OUTPUT_OD

/* Alternate Functions MODE */
#define  AF_PUSH_PULL 	GPIO_MODE_AF_PP
#define  AF_OPEN_DRAIN 	GPIO_MODE_AF_OD

#define  ANALOG			GPIO_MODE_ANALOG

/* Interrupts Detection */
#define  IT_RISING		GPIO_MODE_IT_RISING
#define  IT_FALLING		GPIO_MODE_IT_FALLING
#define  IT_BOTH		GPIO_MODE_IT_RISING_FALLING

/*
#define  GPIO_MODE_EVT_RISING
#define  GPIO_MODE_EVT_FALLING
#define  GPIO_MODE_EVT_RISING_FALLING */

/* SPEED */
#define LOW		 GPIO_SPEED_LOW
#define MEDIUM	 GPIO_SPEED_MEDIUM
#define FAST	 GPIO_SPEED_FAST
#define MAXSPEED GPIO_SPEED_HIGH

/* PULL TYPES */
#define  NOPULL 	GPIO_NOPULL
#define  PULLUP		GPIO_PULLUP
#define  PULLDOWN	GPIO_PULLDOWN

typedef struct{
    uint16_t Pin;
    uint32_t Mode;
    uint32_t Pull;
    uint32_t Speed;
}GPIO_SimpleConfig;

typedef struct{
	GPIO_TypeDef * GPIO;
    uint16_t Pin;
    uint32_t Mode;
    uint32_t Pull;
    uint32_t Speed;
    uint8_t Alternate;
}GPIO_AF_Config;

void MX_GPIO_Init(void);
void AF_GPIO_Init(GPIO_AF_Config);

#endif /*__ pinoutConfig_H */
