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

SD_HandleTypeDef hsd;
HAL_SD_CardInfoTypedef SDCardInfo;

uint8_t retSD;    /* Return value for SD */
char SD_Path[4];  /* SD logical drive path */

FATFS fileSystem;
FIL linkedFile;

void FATFS_Init();
void FATFS_LinkFile(const char* filename, uint8_t mode);
void FATFS_UnlinkFile();
void FATFS_fread();
uint8_t FATFS_fgets();

#endif /* INC_FATFS_H_ */
