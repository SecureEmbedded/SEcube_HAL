/*
 * mcu_ports.h
 *
 *  Created on: 20 nov 2016
 *      Author: raidenfox
 */

#ifndef MCU_PORTS_H_
#define MCU_PORTS_H_

/* FPGA JTAG PROTOCOL PINS */
#define FPGA_TCK_Pin GPIO_PIN_4
#define FPGA_TCK_GPIO_Port GPIOE
#define FPGA_TDI_Pin GPIO_PIN_3
#define FPGA_TDI_GPIO_Port GPIOE
#define FPGA_TDO_Pin GPIO_PIN_2
#define FPGA_TDO_GPIO_Port GPIOE
#define FPGA_TMS_Pin GPIO_PIN_5
#define FPGA_TMS_GPIO_Port GPIOE

/* FPGA PROGRAMMING */
#define FPGA_PROGRAMN_Pin GPIO_PIN_6
#define FPGA_PROGRAMN_GPIO_Port GPIOE

/* FPGA BUS CONTROL */
#define FPGA_BUS_NOE GPIO_PIN_4
#define FPGA_BUS_NWE GPIO_PIN_5
#define FPGA_BUS_NE1 GPIO_PIN_7
#define FPGA_BUS_NE2 GPIO_PIN_9
#define FPGA_BUS_NOE_NWE_NE1_Port GPIOD
#define FPGA_BUS_NE2_Port GPIOG

/* FPGA I/O BUS */
/* First 6-bit block */
#define FPGA_BUS_A0_Pin GPIO_PIN_0
#define FPGA_BUS_A1_Pin GPIO_PIN_1
#define FPGA_BUS_A2_Pin GPIO_PIN_2
#define FPGA_BUS_A3_Pin GPIO_PIN_3
#define FPGA_BUS_A4_Pin GPIO_PIN_4
#define FPGA_BUS_A5_Pin GPIO_PIN_5
#define FPGA_BUS_A_GPIO_Port GPIOF

/* Second 16-bit IO block */
#define FPGA_BUS_D0 GPIO_PIN_14
#define FPGA_BUS_D1 GPIO_PIN_15
#define FPGA_BUS_D2 GPIO_PIN_0
#define FPGA_BUS_D3 GPIO_PIN_1
#define FPGA_BUS_D13 GPIO_PIN_8
#define FPGA_BUS_D14 GPIO_PIN_9
#define FPGA_BUS_D15 GPIO_PIN_10
#define FPGA_BUS_D0_3_D13_15_GPIO_Port GPIOD

#define FPGA_BUS_D4 GPIO_PIN_7
#define FPGA_BUS_D5 GPIO_PIN_8
#define FPGA_BUS_D6 GPIO_PIN_9
#define FPGA_BUS_D7 GPIO_PIN_10
#define FPGA_BUS_D8 GPIO_PIN_11
#define FPGA_BUS_D9 GPIO_PIN_12
#define FPGA_BUS_D10 GPIO_PIN_13
#define FPGA_BUS_D11 GPIO_PIN_14
#define FPGA_BUS_D12 GPIO_PIN_15
#define FPGA_BUS_D4_D12_GPIO_Port GPIOE

/* FPGA CONTROLS */
#define FPGA_BUS_CLK GPIO_PIN_4
#define FPGA_BUS_CLK_GPIO_Port GPIOA
#define FPGA_INTN_Pin GPIO_PIN_9
#define FPGA_INTN_GPIO_Port GPIOA
#define FPGA_RST_Pin GPIO_PIN_2
#define FPGA_RST_GPIO_Port GPIOG

/* SMART CARD CONTROLS*/
#define SC_ON_OFF_Pin GPIO_PIN_1
#define SC_ON_OFF_GPIO_Port GPIOE
#define SC_RST_Pin GPIO_PIN_0
#define SC_RST_GPIO_Port GPIOE
#define SC_CLK_Pin GPIO_PIN_7
#define SC_CLK_GPIO_Port GPIOG

/* SMART CARD DATA */
#define SC_IO_Pin GPIO_PIN_6
#define SC_IO_GPIO_Port GPIOC

#define GPIO1_INT_N_OUT_Pin GPIO_PIN_10
#define GPIO1_INT_N_OUT_GPIO_Port GPIOF
#define GPIO0_RST_OUT_Pin GPIO_PIN_3
#define GPIO0_RST_OUT_GPIO_Port GPIOG


#endif /* MCU_PORTS_H_ */
