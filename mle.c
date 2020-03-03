/**
 * mle.c -- 
 *
 * Copyright (c) 2017, Daniil Kulichenko <kulichen@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void prohod(int index, char *contents, int cursor, void *data);

void mle(text txt)
{
	/* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, prohod, txt);
}

static void prohod(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
	UNUSED(cursor);
	if(cursor != -1) {
		int i = 0;
		while(contents[i] != '\0') i++;	
		m(data, index, i - 1);
		}
}
