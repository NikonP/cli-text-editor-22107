 
 /**
 * m.c -- функция загрузки текста из файла
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"



static void move_begin(int index, char *contents, int cursor, void *data);

/**
 * Перемещает текущую строку в начало текста
 */
void copy_begin(text txt)
{
    get_current(txt, move_begin, (void *)txt);
}

static void move_begin(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(cursor);
    UNUSED(contents);
    
    text txt = (text)data;
    
    move_line(txt, index, 0);
    
}
