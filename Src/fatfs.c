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

FRESULT FATFS_CharReadFromFile(char* path, char* namefile, char* outbuffer){
	char* line = (char*) malloc(sizeof(char)*80); /* Line buffer */
	FRESULT fr;    /* FatFs return code */

	/* Register work area to the default drive */
	FRESULT mount = f_mount(&FatFs, path, 0);
	if(mount == FR_OK){
		/* Open a file */
		fr = f_open(&file_handler, namefile, FA_READ);
		if (fr)
			return FR_NO_FILE;

		/* Read all lines */
		while(f_gets(line, file_handler.fsize, &file_handler));
			memcpy(outbuffer,line, file_handler.fsize);
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
