/**
 * showodd.c -- реализует команду вывода хранимого текста на экран, опуская чётные строки
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license. */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
void showodd(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
}

/**
 * Выводит содержимое указанного файла на экран
 */
static void show_line(int index, char *contents, int cursor, void *data)
{
    /* Декларируем неиспользуемые параметры */
    UNUSED(cursor);
    UNUSED(data);

    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Работаем только с чётными строками */ 
    if(index % 2 != 0) {
	/* Выводим строку на экран */
	printf("%s", contents);
    }
}

