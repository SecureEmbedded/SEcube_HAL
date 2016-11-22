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
	FRESULT create;    /* FatFs return code */

	/* Register work area to the default drive */
	FRESULT mount = f_mount(&FatFs, path, 0);
	UINT byte_count;
	if(mount == FR_OK){
		/* Open a file */
		create = f_open(&file_handler, namefile, CREATE_NEW | WR);
		if (create == FR_OK){
			FRESULT write_status = f_write(&file_handler,buffer_tx,sizeof(buffer_tx),&byte_count);

			/* Close the file */
			return f_close(&file_handler);
			}
		}
		else
			return mount;
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


DWORD get_fattime(void)
{
  return 0;
}
