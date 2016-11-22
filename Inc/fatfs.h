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

/* Lets define a buffer of DIM_BUFFER bytes */
#define DIM_BUFFER 1024

/* Access */
#define CREATE_NEW 		FA_CREATE_NEW
#define CREATE_ALWAYS 	FA_CREATE_ALWAYS

/* Operations */
#define RD FA_READ
#define WR FA_WRITE

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
 * buffer_rx: A buffer for the management of the result
 * size: size read
 */
FRESULT FATFS_CharReadFromFile(char* path, char* namefile, char* buffer_rx,int* size);

/* Read a string from file
 * path: The Volume id (0: or others)
 * namefile: File Name and it's extension
 * buffer_tx: A buffer for the transmitted data
 */
FRESULT FATFS_CharWriteToFile(char* path, char* namefile, char* buffer_tx);
#endif
