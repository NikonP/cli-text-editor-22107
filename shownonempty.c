
/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

static void shownonempty_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void shownonempty(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, shownonempty_line, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void shownonempty_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(data);
    UNUSED(index);

    int i = 0;
    int j = 0;
   
    /*Проверка на пустые строки*/
    while(contents[j] == ' ')
	j++;
    if (contents[j+1] == '\0')
	return;
    if (strlen(contents) < 2)
	return;
    
    /* Выводим строку на экран */
    if (cursor != -1){
	while(i != cursor - 1){
	    printf("%c", contents[i]);
	    i++;
	}
	printf("%c", '|');
	while(contents[i] != '\0'){
	    printf("%c", contents[i]);
	    i++;
	}
    }
    else
	printf("%s", contents);
 
}
