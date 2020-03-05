/**
 * showdigitsonly.c -- реализует команду вывода хранимого текста заглавными буквами на экран
 *
 * Copyright (c) 2020,Svetova Kristina  <ksvetova@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла pзаглавными буквами на экран
 */
void showdigitsonly(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);

    /* Выводим строку на экран */
    if (cursor != -1) {
	int i = 0;
	while (i != cursor) {
	    if (isdigit(contents[i])) 
	   
	    putchar(contents[i]);
	    i++;
	}
	printf("|");
	while (contents[i] != '\0')  {
	    if (isdigit(contents[i]))
	        
	    putchar(contents[i]);
	    i++;
	}
    }
    if (cursor == -1) {
	int i = 0;
	while (contents[i] != '\0') {
	    if (isdigit(contents[i]))
        
	    putchar(contents[i]);
	    i++;
	}
    }
}
