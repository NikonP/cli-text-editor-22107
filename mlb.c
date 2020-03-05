/**
 * mlb.c -- функция перемещения курсора в начало строки
 * 
 * Copyright (c) 2020, Sergey Kalyushin <kalyushi@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include "common.h"
#include "text/text.h"

void mlb(text txt)
{
    move_cursor(txt,get_line_cursor(txt), 0);
}
