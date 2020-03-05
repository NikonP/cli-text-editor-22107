/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

static void print_r(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void pr_righter(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, print_r, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void print_r(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);

    if (cursor != -1) {
        printf("%s", contents + cursor);
    } //else printf("%s", contents);
}
