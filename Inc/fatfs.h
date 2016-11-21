/*
 * main.h
 *
 *  Created on: 21 nov 2016
 *      Author: raidenfox
 */


#ifndef __fatfs_H
#define __fatfs_H

#include <string.h>
#include <malloc.h>
#include "ff.h"
#include "ff_gen_drv.h"
#include "sd_diskio.h" /* defines SD_Driver as external */

extern uint8_t retSD; /* Return status for SD
 	 	 	 	 	 	 0 = OK
 	 	 	 	 	 	 */
extern char SD_Path[4]; /* SD logical drive path */

/* File system Work Area for the mounted Logical Drive */
FATFS FatFs;

/* File handler to perform R/W ops */
FIL file_handler;

void FATFS_Init(void);
char* FATFS_GetLabel();
char* FATFS_GetLogicalPath();

/* Read a string from file
 * path: The Volume id (0: or others)
 * namefile: File Name and it's extension
 * outbuffer: A buffer for the management of the result
 */
FRESULT FATFS_CharReadFromFile(char* path, char* namefile, char* outbuffer);

#endif
