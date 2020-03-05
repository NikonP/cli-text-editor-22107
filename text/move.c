/**
 * move.c -- реализует обобщенную функцию перемещения курсора
 *
 * Copyright (c) 2020, Svetova Kristina  <ksvetova@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"
#include <string.h>
/**
 * Меняет позицию курсора
 * 
 * @param txt текст
 * @returns code
 */
int move_cursor(
    text txt,
    unsigned int line_cursor,
    unsigned int position_cursor
)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return -3;
    }

    /* Проверка номера строки */
    if (line_cursor >= (unsigned int)txt->length) {
	return -1;
    }
    
    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);
    
    /* Стартуем с начальной строки текста */
    node *current = txt->begin;
    
    /* Переходим к новой строке */
    for (unsigned int i = 0; i < line_cursor; i++) 
	current = current->next;

    /* Переходим к позиции курсора в строке */
    if (strlen(current->contents) < (position_cursor + 1)) {
	return -2;
    }

    txt->cursor->line = current;
    txt->cursor->position = position_cursor;
    return 0;
}
