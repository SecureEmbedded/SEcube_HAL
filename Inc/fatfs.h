/*
 * ll_fatfs.h
 *
 *  Created on: 26 nov 2016
 *      Author: raidenfox
 */

#ifndef INC_FATFS_H_
#define INC_FATFS_H_

#include "ff.h"
#include "ff_gen_drv.h"
#include "sd_diskio.h"
#include <string.h>
#include <malloc.h>/* defines SD_Driver as external */


#define BLOCK_SIZE 4096

uint32_t refreshed_alg;
uint32_t refreshed_data;

SD_HandleTypeDef hsd;
HAL_SD_CardInfoTypedef SDCardInfo;

uint8_t retSD;    /* Return value for SD */
char SD_Path[4];  /* SD logical drive path */

FATFS fileSystem;
FIL linkedFile;
FIL debugFile;

void FATFS_Init();
void FATFS_LinkFile(const char* filename, uint8_t mode);
void FATFS_UnlinkFile();
void FATFS_fread();
uint8_t FATFS_fgets();
uint32_t FATFS_GetSize(FIL file);
FIL FATFS_fopen(FIL*,const char*filename, FRESULT*, uint8_t);
uint8_t FATFS_fgetc(FIL* linked);
uint8_t FATFS_feof(FIL* linked);
void FATFS_fclose(FIL* linked);
void FATFS_Debug();
void debug(char c);
void FATFS_Abort_Debug();
void FATFS_BlockReading(FIL* file, uint8_t* buffer,uint32_t counter,uint32_t* refreshed_blocks);


#endif /* INC_FATFS_H_ */
