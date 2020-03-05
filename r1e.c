/**
 * r1e.c -- функция удаления gпервой пустой строки из текста
 * 
 * Copyright (c) 2020, Kalyushin Sergey <kalyushi@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void search_empty_line(int index, char *contents, int cursor, void *data);
/**
 * Удаляет первую пустую строку из текста
 */
void r1e(text txt)
{
    /* Применяем функцию searc_empty_line к каждой строке текста */
    process_forward(txt, search_empty_line, txt);
}

static void search_empty_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(cursor);

    if (contents[0] == '\n') {
      	delete_line(data, index);
	if (cursor != -1)
	    move_cursor(data, index, 0);
        data = NULL;
    }
}
