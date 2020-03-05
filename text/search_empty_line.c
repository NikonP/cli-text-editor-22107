/**
 * search_empty_line.c -- возвращает номер первой пустой строки
 *
 * Copyright (c) 2020, Sergey Kalyushin <kalyushi@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"
#include <string.h>
/**
 * Возвращает номер первой пустой строки
 * 
 * @param txt текст
 * @returns number
 */
int search_empty_line(text txt)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return -3;
    }
    
    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);
    
    /* Стартуем с начальной строки текста */
    node *current = txt->begin;
    
    /* Переходим к новой строке */
    int number_empty_line = 0;

    while (current != txt->end) {  
	if (current->contents[0]  == '\n') return number_empty_line; 
	current = current->next;
	number_empty_line++;
    }
    if (current->contents[0] == '\n') return number_empty_line;
    return -1;
}
