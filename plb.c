/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>

#include <string.h>

#include <assert.h>
#include "common.h"
#include "text/text.h"
typedef struct _pair {
	int a;
	int b;
} pair;

static void plb_on_line(int index, char *contents, int cursor, void *data);

/**
 * для вывода на экран части строки от начала до курсора plb;
 */
void plb(text txt)
{

    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, plb_on_line, NULL);
}
/**
 * Выводит содержимое указанного файла на экран
 */
static void plb_on_line(int index, char *contents, int cursor, void *data)
{
	//pair p1 = (pair)data;
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
	//		printf("%d %lld\n", index, ind);
    if(cursor != -1){
  		/* Декларируем неиспользуемые параметры */
		
 		//UNUSED(index);
 		UNUSED(cursor);
	    //UNUSED(data);

		for(int i = 0; i < cursor; i++)
			printf("%c", contents[i]);
		
  	}
}

