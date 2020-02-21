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

static void show_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран в обратном порядке
 * пропуская нечётные строки
 */
void showreveven(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_backward(txt, show_line, NULL);
}

static void show_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(data);

    if(index % 2 == 0) {
        char* to_print = contents;

        /* Проверяем стоит ли курсор на текущей строке */
        if(cursor != -1) {
            to_print = set_cursor(contents, cursor);
        }

        /* Выводим строку на экран */
        printf("%s", to_print);
    }
}
