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
	f_open(&linkedFile, filename, mode);
}

FIL FATFS_fopen(FIL* opened,const char*filename, FRESULT* status, uint8_t mode){
	f_open(opened,filename,mode);
	*status = FR_OK;
	return *opened;
}

uint8_t FATFS_fgetc(FIL* linked){
		  UINT counted;
		  uint8_t buff;
		  f_read(linked, &buff, 1, &counted);
		  debug(buff);
		  //sendTostream(*buff);
		  return buff;
}

void FATFS_BlockReading(FIL* file, uint8_t* buffer,uint32_t counter,uint32_t* refreshed_blocks){

	uint32_t size = FATFS_GetSize(*file);
	uint32_t blocks = (size/BLOCK_SIZE);
	uint32_t byte_blocks = blocks*BLOCK_SIZE;
	uint32_t spare = size-byte_blocks;
	if(counter == 0){
		for(int i = 0; i< BLOCK_SIZE; i++){
		  	  uint8_t c = FATFS_fgetc(file);
		  	  buffer[i] = c;
		    }
		(*refreshed_blocks)++;
	}else if(counter%BLOCK_SIZE == 0){
		if((*refreshed_blocks < blocks)){
		    for(int i = 0; i< BLOCK_SIZE; i++){
		  	  uint8_t c = FATFS_fgetc(file);
		  	  buffer[i] = c;
		    }
			(*refreshed_blocks)++;
		}else{
		    for(int i = 0; i< spare; i++){
		  	  uint8_t c = FATFS_fgetc(file);
		  	  buffer[i] = c;
		    }
		}
	}
}

void FATFS_Debug(){
	FRESULT status;
	//debugFile = FATFS_fopen("debug.txt", &status, FA_WRITE | FA_CREATE_ALWAYS);
}

void debug(char c){
	unsigned char bw = (unsigned char)c;
	f_putc(bw,&debugFile);
}

void FATFS_Abort_Debug(){
	  f_close(&debugFile);
}

uint8_t FATFS_feof(FIL* linked){
	if(f_eof(linked)){
		return 1;
	}
	else return 0;
}

void FATFS_fread(){
		  uint32_t size = linkedFile.fsize;
		  UINT counted;
		  uint8_t* buff = (uint8_t*) malloc(sizeof(uint8_t));
		  for(int i = 0; i < size ; i++){
			  f_read(&linkedFile, buff, 1, &counted);
			  //sendTostream(*buff);
		  }
}

uint8_t FATFS_fgets(){
		  UINT counted;
		  uint8_t* buff = (uint8_t*) malloc(sizeof(uint8_t));
		  f_read(&linkedFile, buff, 1, &counted);
		  return *buff;
}

uint32_t FATFS_GetSize(FIL file){
	return file.fsize;
}

void FATFS_UnlinkFile(){
	  f_close(&linkedFile);
}

void FATFS_fclose(FIL* linked){
	  f_close(linked);
}
