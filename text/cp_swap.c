/**
 * cp_swap.c -- функции для добавления строк
 *
 * Copyright (c) 2020, Filin Nikolay <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

void swap(text txt)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    }

    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);

    if (txt->cursor->line == txt->begin) return;

    /* Стартуем с начальной строки текста */
    	node *list2 = txt->cursor->line->previous;
	node *list3 = txt->cursor->line;
	node *list1 = NULL;
	node *list4 = NULL;

	/*Переставновка указателей на следующие строки*/
    	if (list2->previous == NULL) txt->begin = txt->cursor->line; else list1 = list2->previous;

 	if (txt->cursor->line != txt->end) list4 = txt->cursor->line->next; else {txt->end = list2; list2->next = NULL;}

    	if (list1 != NULL) { list1->next = list3; list3->previous = list1; }

	list3->next = list2;
	list2->previous = list3;

	if (list4 != NULL) { list2->next = list4; list4->previous = list2; }
}
