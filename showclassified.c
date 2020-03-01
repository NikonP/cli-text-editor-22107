/**
 * showclassified.c -- реализует команду вывода хранимого текста на экран
 * с заменой печатных символов на "*"
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>

#include <string.h>

#include <assert.h>
#include "common.h"
#include "text/text.h"

static void showclassified_line(int index, char *contents, int cursor, void *data);

void showclassified(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, showclassified_line, NULL);
}

static void showclassified_line(int index, char *contents, int cursor, void *data)
{
    assert(contents != NULL);

    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);

	for(int i = 0; i < strlen(contents); i++){
		if(contents[i] != ' ' && contents[i] != '\n') {
			printf("*");
		} else {
			printf("%c", contents[i]);
		}
	}
}
