/**
 * showreveven.c -- вывод строк в обратном порядке с пропуском нечётных строк
 *
 * Copyright (c) 2020, Nikon Podgorny <podgorny@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

/**
* Выводит содержимое указанного файла на экран в обратном порядке
* пропуская нечётные строки
*/
void showreveven()
{
    /* code */
}

static void show_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);

    /* Выводим строку на экран */
    printf("%s", contents);
}
