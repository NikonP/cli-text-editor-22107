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

/**
 * Удаляет первую пустую строку из текста
 */
void r1e(text txt)
{
    int number_empty_line = search_empty_line(txt);
    if (number_empty_line == -1) return;
    if(delete_line(txt, number_empty_line) == -1) move_cursor(txt, number_empty_line, 0);
}
