/**
 * move.c -- реализует обобщенную функцию перемещения курсора
 *
 * Copyright (c) 2020, Svetova Kristina  <ksvetova@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Меняет позицию курсора
 * 
 * @param txt текст
 * @returns none
 */
void move(
    text txt,
    int line_cursor,
    int position_cursor
)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    } 
    
    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);
    
    /* Стартуем с начальной строки текста */
    node *current = txt->begin;
    
    /* Переходим к новой строке */
    for (int i = 1; i < line_cursor; i++) 
	current = current->next;
    
    txt->cursor->line = current;
    txt->cursor->position = position_cursor;
    
}
