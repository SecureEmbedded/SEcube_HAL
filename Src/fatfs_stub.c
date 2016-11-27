/*
 * fatfs_stub.c
 *
 *  Created on: 26 nov 2016
 *      Author: raidenfox
 */

#include "fatfs_stub.h"

void external_read(){
	uint8_t ext = FATFS_fgets();
	uint8_t sec = ext;
}
