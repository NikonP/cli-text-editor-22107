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

static void show_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);

    /* Проверяем стоит ли курсор на текущей строке */
    if(cursor != -1) {
        /* Устанавливаем курсор в заданную позицию в строке*/
        contents[cursor] = '|';

        /* Если курсор в конце строки, то после него необходимо добавить \n */
        if(cursor == (int) strlen(contents) - 1) {
            contents[cursor + 1] = '\n';
        }
    }

    /* Выводим строку на экран */
    printf("%s", contents);
}
