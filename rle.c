/**
 * rle.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2020, Filin Nikolay <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#include <string.h>

static void rle_line(int index, char *contents, int cursor, void *data);

void rle(text txt)
{
    /* Применяем функцию rle_line к каждой строке текста */
    process_forward(txt, rle_line, NULL);
}

static void rle_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);

    int a;
    int i = 0;

    /* Выводим строку на экран */
        if (cursor != -1) {
                while (i != cursor){
                        if ((a = strlen(contents)) == cursor && i + 1 == cursor) a = -1; else
                        printf("%c", contents[i]);
                        i++;
                }
                        printf("|");
			contents[i] = '\n';
			contents[i + 1] = '\0';
			printf("%c", contents[i]);
        } else printf("%s", contents);
}

