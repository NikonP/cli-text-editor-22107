/**
 * showupfirst.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Daniil Kulichenko <kulichen@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void showupfirst(text txt)
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
	printf("%c", toupper(contents[0]));
	int i = 1;
	while (contents[i] != '\0') {
		if ((contents[i - 1] == ' ')) printf("%c", toupper(contents[i]));
		else printf("%c", contents[i]);
		if (cursor == i + 2) printf("|");
		i++;
	}	
}
