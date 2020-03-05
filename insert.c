 
/**
 * save.c -- функция загрузки текста из файла
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



static void insert_line(int index, char *contents, int cursor, void *data);

/**
 * Сохраняет содержимое в указанный файл
 */
void insert(text txt, char *contents)
{
    get_current(txt, insert_line, (void *)contents);
}

static void insert_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);

    char *inclusion = (char *)data;
    char *leftover = contents + cursor;
    
    /* Проверка на переполнение */
    if (strlen(contents) + strlen(inclusion) > MAXLINE) {
        printf("The insert line is too long!\n");
        return;
    }
    
    char buf[MAXLINE + 1];
    memset(buf, '\0', MAXLINE + 1);
    
    /* Формирование новой строки */
    strncpy(buf, contents, cursor);
    strcat(buf, inclusion);
    strcat(buf, leftover);
    
    /* Замена старой строки */
    strcpy(contents, buf);
    contents[MAXLINE] = '\0';
    
}
