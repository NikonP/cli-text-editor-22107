/**
 * delete_line.c -- реализует функцию удаление строки
 *
 * Copyright (c) 2020, Sergey Kalyushin <kalyushi@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Удаляет строку
 * 
 * @param txt текст
 * @returns code
 */
int delete_line(
    text txt,
    unsigned int line_number
)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return -2;
    }

    /* Проверяем наличие данной строчки */
    if ((unsigned int)txt->length < line_number + 1){
	return -3;
    }
    
    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);
    
    /* Стартуем с начальной строки текста */
    node *current = txt->begin;
    
    /* Переходим к новой строке */
    for (unsigned int i = 0; i < line_number; i++){ 
	current = current->next;
    }

    /* Меняем указатель следующего на предыдущий элемент */
    if ((current == txt->begin) || (current == txt->end)){
        if ((current == txt->begin) && (current == txt->end)) { // Если текст из одной строки
            free (current);
            txt->begin = NULL;
            txt->end = NULL;
            txt->cursor->line = NULL;
            txt->cursor->position = 0;
            txt->length = txt->length - 1;
            return 0;
        } else {
            if (current == txt->begin) // Если удаляется первая строка текста
            {
                txt->begin = current->next;
                current->next->previous = NULL;
            }
            if (current == txt->end) // Если удаляется последняя строка 
 	    { 
                txt->end = current->previous;
                current->previous->next = NULL;
            }
        }
    } else {
        current->next->previous = current->previous;
        current->previous->next = current->next;
    }

    if (current == txt->cursor->line) {
        return -1; // Если удаляется линия с курсором
    }

    /*Обновляем параметр длины */
    txt->length = txt->length - 1;
    return 0;
}
