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

    /* Объявляем используемые переменные */
    int i;
    char line[MAXLINE + 2];

    /* Декларируем неиспользуемые параметры */
    UNUSED(data);

    if(index % 2 == 0) {
        /* Проверяем положение курсора */
        if (cursor > -1) {
        	/* Копируем первую часть строки */
        	for (i = 0; i < cursor; i++) {
        	    if (contents[i] == '\n')
        		break;
        	    line[i] = contents[i];
        	}
        	line[i++] = '|';
        	/* Копируем вторую часть строки */
        	for (; contents[i-1] != '\0'; i++)
        	    line[i] = contents[i-1];
        	line[i] = '\0';
        	/* Выводим строку на экран */
        	printf("%s", line);
        } else {
            /* Выводим строку на экран */
            printf("%s", contents);
        }
    }
}
