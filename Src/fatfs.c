/*
 * main.h
 *
 *  Created on: 21 nov 2016
 *      Author: raidenfox
 */

#include "fatfs.h"

uint8_t retSD;    /* Status value for SD
 	 	 	 	 	 0 = OK */
char SD_Path[4];  /* SD logical drive path */



void FATFS_Init(void)
{
  /*## FatFS: Link the SD driver ###########################*/
  retSD = FATFS_LinkDriver(&SD_Driver, SD_Path);

}

char* FATFS_GetLogicalPath(){
	return SD_Path;
}

char* FATFS_GetLabel(){
	char str[24];

	/* Get volume label of the default drive */
	f_getlabel(FATFS_GetLogicalPath(), str, 0);
	return str;
}

FRESULT FATFS_CharWriteToFile(char* path, char* namefile, char* buffer_tx){
	/* Register work area to the default drive */
	status.mountStatus = f_mount(&FatFs, path, 0);
	UINT byte_count;
	if(status.mountStatus == FR_OK){
		/* Open a file */
		status.createStatus = f_open(&file_handler, namefile, FA_OPEN_ALWAYS | WR);

		if (status.createStatus == FR_OK){
			status.writeStatus = f_write(&file_handler,buffer_tx,sizeof(buffer_tx),&byte_count);
			/* Close the file */
			status.closeStatus  = f_close(&file_handler);
			return status.closeStatus ;
			}
		}
		else
			return status.mountStatus ;
}

FRESULT FATFS_CharReadFromFile(char* path, char* namefile, char* buffer_rx, int* size){
	FRESULT fr;    /* FatFs return code */

	/* Register work area to the default drive */
	FRESULT mount = f_mount(&FatFs, path, 0);
	if(mount == FR_OK){
		/* Open a file */
		fr = f_open(&file_handler, namefile, RD);
		if (fr)
			return FR_NO_FILE;

		uint32_t sizeread = (uint32_t) file_handler.fsize +1;
		*size = sizeread;
		char* line = (char*) malloc(sizeread*sizeof(char));

		/* Read all lines */
		 while(f_eof(&file_handler) == 0){
			 f_gets(line, sizeread, &file_handler);
		 }
		memcpy(buffer_rx,line,sizeread*sizeof(char));
		free(line);

		/* Close the file */
		return f_close(&file_handler);
	}
	else
		return mount;
}



FRESULT FATFS_ByteReadFromFile(char* path, char* namefile, uint8_t* buffer_rx, int* size){
	UINT counter;
	FRESULT fr;    /* FatFs return code */

	/* Register work area to the default drive */
	FRESULT mount = f_mount(&FatFs, path, 0);
	if(mount == FR_OK){
		/* Open a file */
		fr = f_open(&file_handler, namefile, RD);
		if (fr)
			return FR_NO_FILE;

		uint32_t sizeread = (uint32_t) file_handler.fsize;
		uint8_t* line = (uint8_t*) malloc(sizeread*sizeof(uint8_t));

		/* Read all lines */
		 //while(f_eof(&file_handler) == 0){
			 f_read(&file_handler,line, sizeread, &counter);
			 *size = counter;
		 //}
		memcpy(buffer_rx,line,sizeread*sizeof(uint8_t));
		free(line);

		/* Close the file */
		return f_close(&file_handler);
	}
	else
		return mount;
}


DWORD get_fattime(void)
{
  return 0;
}
