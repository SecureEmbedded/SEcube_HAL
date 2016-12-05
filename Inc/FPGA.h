/*
 * FPGA.h
 *
 */

#ifndef APPLICATION_SRC_FPGA_H_
#define APPLICATION_SRC_FPGA_H_

#include "flashmem.h"

#define FLASH_DATA_ADDR   ADDR_FLASH_SECTOR_5   /* Start @ of user Flash area */
#define FLASH_ALGO_ADDR   ADDR_FLASH_SECTOR_17   /* Start @ of user Flash area */

int32_t     B5_FPGA_Programming (const char*,const char*);
void        B5_FPGA_SetMux (uint8_t mux);
void        B5_FPGA_FpgaCpuGPIO (uint8_t gpioNum, GPIO_PinState set);

#endif /* APPLICATION_SRC_FPGA_H_ */
