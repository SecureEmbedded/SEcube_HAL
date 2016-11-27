/*
 * ll_fatfs.c
 *
 *  Created on: 26 nov 2016
 *      Author: raidenfox
 */

#include "fatfs.h"

void FATFS_Init(){
	  retSD = FATFS_LinkDriver(&SD_Driver, SD_Path);
	  f_mount(&fileSystem, SD_Path, 1);
}

void FATFS_LinkFile(const char* filename, uint8_t mode){
	FRESULT res = f_open(&linkedFile, filename, mode);
}

void FATFS_fread(){
		  uint32_t size = linkedFile.fsize;
		  UINT counted;
		  int counter;
		  uint8_t* buff2 = (uint8_t*) malloc(size*sizeof(uint8_t));
		  uint8_t* buff = (uint8_t*) malloc(sizeof(uint8_t));
		  for(int i = 0; i < size ; i++){
			  f_read(&linkedFile, buff, 1, &counted);
			  //sendTostream(*buff);
		  }
}

uint8_t FATFS_fgets(){
		  UINT counted;
		  int counter;
		  uint8_t* buff = (uint8_t*) malloc(sizeof(uint8_t));
		  f_read(&linkedFile, buff, 1, &counted);
		  return *buff;
}

void FATFS_UnlinkFile(){
	  f_close(&linkedFile);
}
