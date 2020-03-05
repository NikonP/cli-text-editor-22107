/**
 * showtrimmedfromstart.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2020, Filin Nikolay <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#include <ctype.h>
#include <string.h>

static void showtrimmedfromstart_line(int index, char *contents, int cursor, void *data);

void showtrimmedfromstart(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, showtrimmedfromstart_line, NULL);
}

static void showtrimmedfromstart_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);

    /*Обрабатываем строку*/
    int i = 0;
    while(isspace(contents[i]) != 0) i++;

    /* Выводим строку на экран */
    printf("%s", contents + i);
}
