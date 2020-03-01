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

static void showclassified_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
int getlength(text txt){
	return getlength1(txt);
}

void showclassified(text txt)
{
	int o = getlength(txt);
	
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, showclassified_line, o);
}

static void showclassified_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    int y = (int)data;
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);
	for(int i = 0; i < strlen(contents)-1; i++){
		if(contents[i]!=' ' ||contents[i]!='\n' || contents[i]!='\0')
			printf("*");
		else
			printf("%c", contents[i]);
	}
	if(index == y-1)
		printf("*");
	printf("\n");
    
}

