/**
 * save.c -- функция сохранения файла
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void save_line(int index, char *contents, int cursor, void *data);

/**
 * Сохраняет содержимое открытого файла
 */

void save(text txt, char *filename)
{
    FILE *f;

    /* Открываем файл для записи, контролируя ошибки */
    if ((f = fopen(filename, "w")) == NULL) {
        printf("Can't save to file %s\n", filename);
        return;
    }

    /* Применяем функцию save_line к каждой строке текста */
    process_forward(txt, save_line, f);

    fclose(f);
}

static void save_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);

    /* Сохраняем строку в файл */
    FILE* f = (FILE*)data;
    fprintf(f, "%s", contents);
}
