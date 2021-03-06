/**
 ******************************************************************************
  * @file    flashmem.h
  * @brief   This file describes the primitives adopted to write on a flash
  ******************************************************************************
  * @attention
  *
  * HOW TO USE THIS DRIVER
  *
  * Initializate the Flash_Init function, passing the first address of the area
  * to write. Then use the ProgramData primitive, passing the namefile to write
  * on the flash, before close the opeartions on the Flash with the Lock HAL
  * primitive
  *
  ******************************************************************************
  */

#ifndef INC_FLASH_H_
#define INC_FLASH_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "fatfs.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Base address of the Flash sectors Bank 1 */
#define ADDR_FLASH_SECTOR_0     ((uint32_t)0x08000000) /* Base @ of Sector 0, 16 Kbytes */
#define ADDR_FLASH_SECTOR_1     ((uint32_t)0x08004000) /* Base @ of Sector 1, 16 Kbytes */
#define ADDR_FLASH_SECTOR_2     ((uint32_t)0x08008000) /* Base @ of Sector 2, 16 Kbytes */
#define ADDR_FLASH_SECTOR_3     ((uint32_t)0x0800C000) /* Base @ of Sector 3, 16 Kbytes */
#define ADDR_FLASH_SECTOR_4     ((uint32_t)0x08010000) /* Base @ of Sector 4, 64 Kbytes */
#define ADDR_FLASH_SECTOR_5     ((uint32_t)0x08020000) /* Base @ of Sector 5, 128 Kbytes */
#define ADDR_FLASH_SECTOR_6     ((uint32_t)0x08040000) /* Base @ of Sector 6, 128 Kbytes */
#define ADDR_FLASH_SECTOR_7     ((uint32_t)0x08060000) /* Base @ of Sector 7, 128 Kbytes */
#define ADDR_FLASH_SECTOR_8     ((uint32_t)0x08080000) /* Base @ of Sector 8, 128 Kbytes */
#define ADDR_FLASH_SECTOR_9     ((uint32_t)0x080A0000) /* Base @ of Sector 9, 128 Kbytes */
#define ADDR_FLASH_SECTOR_10    ((uint32_t)0x080C0000) /* Base @ of Sector 10, 128 Kbytes */
#define ADDR_FLASH_SECTOR_11    ((uint32_t)0x080E0000) /* Base @ of Sector 11, 128 Kbytes */

/* Base address of the Flash sectors Bank 2 */
#define ADDR_FLASH_SECTOR_12     ((uint32_t)0x08100000) /* Base @ of Sector 0, 16 Kbytes */
#define ADDR_FLASH_SECTOR_13     ((uint32_t)0x08104000) /* Base @ of Sector 1, 16 Kbytes */
#define ADDR_FLASH_SECTOR_14     ((uint32_t)0x08108000) /* Base @ of Sector 2, 16 Kbytes */
#define ADDR_FLASH_SECTOR_15     ((uint32_t)0x0810C000) /* Base @ of Sector 3, 16 Kbytes */
#define ADDR_FLASH_SECTOR_16     ((uint32_t)0x08110000) /* Base @ of Sector 4, 64 Kbytes */
#define ADDR_FLASH_SECTOR_17     ((uint32_t)0x08120000) /* Base @ of Sector 5, 128 Kbytes */
#define ADDR_FLASH_SECTOR_18     ((uint32_t)0x08140000) /* Base @ of Sector 6, 128 Kbytes */
#define ADDR_FLASH_SECTOR_19     ((uint32_t)0x08160000) /* Base @ of Sector 7, 128 Kbytes */
#define ADDR_FLASH_SECTOR_20     ((uint32_t)0x08180000) /* Base @ of Sector 8, 128 Kbytes  */
#define ADDR_FLASH_SECTOR_21     ((uint32_t)0x081A0000) /* Base @ of Sector 9, 128 Kbytes  */
#define ADDR_FLASH_SECTOR_22     ((uint32_t)0x081C0000) /* Base @ of Sector 10, 128 Kbytes */
#define ADDR_FLASH_SECTOR_23     ((uint32_t)0x081E0000) /* Base @ of Sector 11, 128 Kbytes */

//#define FLASH_USER_END_ADDR     ADDR_FLASH_SECTOR_7   /* End @ of user Flash area */

/**
  * @brief  Configures First Algo-Data Address for the Flash Area.
  * @param  None
  * @retval None
  */
void Flash_Init();


/**
  * @brief  Lock the Flash.
  * @param  None
  * @retval None
  */
void Flash_Lock();


/**
  * @brief  Erase the areas in the Flash.
  * @param  size: Numbers of areas to erase
  * @retval None
  */
void EraseFlash(uint32_t size);

/**
  * @brief  Configures First Algo-Data Address for the Flash Area.
  * @param  address: First address to start write the data passed as 2nd parameter
  * @param  namefile: Name of the file to read from uSD card
  * @param  siz: pointer to return the number of written data
  * @retval None
  */
void ProgramData(uint32_t address,const char* namefile,uint32_t* siz);


void ProgramFlashByte(uint8_t buffer);


/**
  * @brief  Configures First Algo-Data Address for the Flash Area.
  * @param  addr: read a byte from a passed address
  * @retval byte read
  */
uint8_t ReadFlash(uint32_t addr);
__IO uint32_t VerifyData(uint8_t data);
static uint32_t GetSector(uint32_t Address);


#endif /* INC_FLASH_H_ */
