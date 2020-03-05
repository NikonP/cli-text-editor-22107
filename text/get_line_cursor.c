/**
 * get_line_cursor.c -- возвращает номер строки с  курсором
 *
 * Copyright (c) 2020, Sergey Kalyushin <kalyushi@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Меняет позицию курсора
 * 
 * @param txt текст
 * @returns line_cursor
 */
int  get_line_cursor (text txt)
{
    int number_line =  0;
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return number_line;
    } 
    
    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);
    
    /* Стартуем с начальной строки текста */
    node *current = txt->begin;
    if (current == txt->cursor->line) {
	return number_line;
    } else {
    /* Переходим к новой строке */
	while (current != txt->cursor->line) {
	    current = current->next;
	    number_line++;
	}
	return number_line;
    }
}
