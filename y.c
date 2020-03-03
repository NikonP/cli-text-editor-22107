/**
 * y.c -- функция вставки строки после курсора с заменой
 * 
 * Copyright (c) 2020, Harichev Evgeny <harichev@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include "common.h"
#include "text/text.h"
#include <assert.h>

void y(text txt, char *line) { 
   /* Вставляем строку */
   y_line(txt,line);
   /* Выводим текст */
   show(txt);
}
