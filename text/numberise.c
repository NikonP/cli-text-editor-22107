 /**
 * numberise.c -- функция конвертации из char -> int
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "_text.h"

#define MAXLINE 255

int numberise(char* num){

	int ret = 0;
	unsigned int length = strlen(num);
	for(unsigned int i = 0; i < length;i++){
		ret = ret * 10 + (num[i] - '0');
	}	
	
	return ret;

}

