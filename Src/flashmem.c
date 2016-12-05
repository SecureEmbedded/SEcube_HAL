/*
 * flash.c
 *
 *  Created on: 26 nov 2016
 *      Author: raidenfox
 */

#include "flashmem.h"
#include "fatfs.h"

/*Variable used for Erase procedure*/
static FLASH_EraseInitTypeDef EraseInitStruct;

/* Private variables ---------------------------------------------------------*/
uint8_t ByteAddress = 0;
uint32_t FirstSector = 0, NbOfSectors = 0, Address = 0;
uint32_t EndAddress;
uint32_t SectorError = 0;
__IO uint8_t data8 = 0 , MemoryProgramStatus = 0;

void Flash_Init(uint32_t address){
	Address = address;
	/* Unlock the Flash to enable the flash control register access *************/
	HAL_FLASH_Unlock();
}

void ProgramData(uint32_t address,const char* namefile,uint32_t* siz){
	/* Program All the Data */
	FIL opened;
	FRESULT status;
	FATFS_fopen(&opened,namefile,&status,FA_READ);
	uint32_t size = FATFS_GetSize(opened);
	*siz = size;
	/* Erase the Flash Memory */
	EraseFlash(size);

	for(int i = 0; i< size; i++){
		uint8_t c = FATFS_fgetc(&opened);
		ProgramFlashByte(c);
	  }
	Address = address;
	FATFS_fclose(&opened);
	HAL_FLASH_Lock();
}

void Flash_Lock(){
	HAL_FLASH_Lock();
}

void EraseFlash(uint32_t size){
	/* Erase the user Flash area
	(area defined by FLASH_USER_START_ADDR and FLASH_USER_END_ADDR) ***********/

	/* Get the 1st sector to erase */
	FirstSector = GetSector(Address);

	/* Get the number of sector to erase from 1st sector*/
	EndAddress = Address + size;
	NbOfSectors = GetSector(EndAddress) - FirstSector + 1;


	/* Fill EraseInit structure*/
	EraseInitStruct.TypeErase = TYPEERASE_SECTORS;
	EraseInitStruct.VoltageRange = VOLTAGE_RANGE_3;
	EraseInitStruct.Sector = FirstSector;
	EraseInitStruct.NbSectors = NbOfSectors;
	if (HAL_FLASHEx_Erase(&EraseInitStruct, &SectorError) != HAL_OK)
	  {
	    /*
	      Error occurred while sector erase.
	      User can add here some code to deal with this error.
	      SectorError will contain the faulty sector and then to know the code error on this sector,
	      user can call function 'HAL_FLASH_GetError()'
	    */
	        HAL_FLASH_GetError();


	  }
}

void ProgramFlashByte(uint8_t buffer){
	  EndAddress = Address + 1;
	  int i = 0;
	  while (Address < EndAddress){
	  	  {
	  	    if (HAL_FLASH_Program(TYPEPROGRAM_BYTE, Address, buffer) == HAL_OK)
	  	    {
	  	      Address = Address + 1;
	  	    }
	  	    else
	  	    {
	  	      /* Error occurred while writing data in Flash memory.
	  	         User can add here some code to deal with this error */

	  	    	HAL_FLASH_GetError();
	  	    }
	  	  }
	  	  i++;
	  }

}

uint8_t ReadFlash(uint32_t addr){
	data8 = *(__IO uint8_t*)addr;
	return data8;
}

/*

__IO uint32_t VerifyData(uint8_t data){
	Address = FLASH_USER_START_ADDR;
	  MemoryProgramStatus = 0x0;

	  while (Address < FLASH_USER_END_ADDR)
	  {
	    data8 = *(__IO uint8_t*)Address;

	    if (data8 != data)
	    {
	      MemoryProgramStatus++;
	      return MemoryProgramStatus;
	    }

	    Address = Address + 1;
	  }
	  return MemoryProgramStatus;
}
*/
static uint32_t GetSector(uint32_t Address)
{
  uint32_t sector = 0;

  if((Address < ADDR_FLASH_SECTOR_1) && (Address >= ADDR_FLASH_SECTOR_0))
  {
    sector = FLASH_SECTOR_0;
  }
  else if((Address < ADDR_FLASH_SECTOR_2) && (Address >= ADDR_FLASH_SECTOR_1))
  {
    sector = FLASH_SECTOR_1;
  }
  else if((Address < ADDR_FLASH_SECTOR_3) && (Address >= ADDR_FLASH_SECTOR_2))
  {
    sector = FLASH_SECTOR_2;
  }
  else if((Address < ADDR_FLASH_SECTOR_4) && (Address >= ADDR_FLASH_SECTOR_3))
  {
    sector = FLASH_SECTOR_3;
  }
  else if((Address < ADDR_FLASH_SECTOR_5) && (Address >= ADDR_FLASH_SECTOR_4))
  {
    sector = FLASH_SECTOR_4;
  }
  else if((Address < ADDR_FLASH_SECTOR_6) && (Address >= ADDR_FLASH_SECTOR_5))
  {
    sector = FLASH_SECTOR_5;
  }
  else if((Address < ADDR_FLASH_SECTOR_7) && (Address >= ADDR_FLASH_SECTOR_6))
  {
    sector = FLASH_SECTOR_6;
  }
  else if((Address < ADDR_FLASH_SECTOR_8) && (Address >= ADDR_FLASH_SECTOR_7))
  {
    sector = FLASH_SECTOR_7;
  }
  else if((Address < ADDR_FLASH_SECTOR_9) && (Address >= ADDR_FLASH_SECTOR_8))
  {
    sector = FLASH_SECTOR_8;
  }
  else if((Address < ADDR_FLASH_SECTOR_10) && (Address >= ADDR_FLASH_SECTOR_9))
  {
    sector = FLASH_SECTOR_9;
  }
  else if((Address < ADDR_FLASH_SECTOR_11) && (Address >= ADDR_FLASH_SECTOR_10))
  {
    sector = FLASH_SECTOR_10;
  }
  else if((Address < ADDR_FLASH_SECTOR_12) && (Address >= ADDR_FLASH_SECTOR_11))
  {
    sector = FLASH_SECTOR_11;
  }
  else if((Address < ADDR_FLASH_SECTOR_13) && (Address >= ADDR_FLASH_SECTOR_12))
  {
    sector = FLASH_SECTOR_12;
  }
  else if((Address < ADDR_FLASH_SECTOR_14) && (Address >= ADDR_FLASH_SECTOR_13))
  {
    sector = FLASH_SECTOR_13;
  }
  else if((Address < ADDR_FLASH_SECTOR_15) && (Address >= ADDR_FLASH_SECTOR_14))
  {
    sector = FLASH_SECTOR_14;
  }
  else if((Address < ADDR_FLASH_SECTOR_16) && (Address >= ADDR_FLASH_SECTOR_15))
  {
    sector = FLASH_SECTOR_15;
  }
  else if((Address < ADDR_FLASH_SECTOR_17) && (Address >= ADDR_FLASH_SECTOR_16))
  {
    sector = FLASH_SECTOR_16;
  }
  else if((Address < ADDR_FLASH_SECTOR_18) && (Address >= ADDR_FLASH_SECTOR_17))
  {
    sector = FLASH_SECTOR_17;
  }
  else if((Address < ADDR_FLASH_SECTOR_19) && (Address >= ADDR_FLASH_SECTOR_18))
  {
    sector = FLASH_SECTOR_18;
  }
  else if((Address < ADDR_FLASH_SECTOR_20) && (Address >= ADDR_FLASH_SECTOR_19))
  {
    sector = FLASH_SECTOR_19;
  }
  else if((Address < ADDR_FLASH_SECTOR_21) && (Address >= ADDR_FLASH_SECTOR_20))
  {
    sector = FLASH_SECTOR_20;
  }
  else if((Address < ADDR_FLASH_SECTOR_22) && (Address >= ADDR_FLASH_SECTOR_21))
  {
    sector = FLASH_SECTOR_21;
  }
  else if((Address < ADDR_FLASH_SECTOR_23) && (Address >= ADDR_FLASH_SECTOR_22))
  {
    sector = FLASH_SECTOR_22;
  }
  else/*(Address < FLASH_END_ADDR) && (Address >= ADDR_FLASH_SECTOR_23))*/
  {
    sector = FLASH_SECTOR_23;
  }

  return sector;
}
