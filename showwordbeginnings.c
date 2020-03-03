/**
 * showwordbeginnings.c -- команда вывода 1 букв слов
 *
 * Copyright (c) 2020, Harichev Evgeny <harichev@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void showwordbeginnings(text txt)
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
    UNUSED(cursor);
    /* Выводим начала слов на экран */
    printf("%c", contents[0]); // Первый символ в строке
    int i=1;
	while (contents[i] != '\0'){ 
	    if(contents[i-1]==' ') // Затем, если предыдущий символ - пробел, выводим символ
	    	printf("%c", contents[i]);
	    else printf(" ");
	    i++;
	}
    printf("\n");
   
    
}
