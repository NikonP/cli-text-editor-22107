/**
 * r1ne.c -- 
 * 
 * Copyright (c) 2020, Kulichenko Daniil <kulichen@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Добавляет одну строку к тексту
 * @param txt текст
 * @param contents новая строка
 * @returns none
 */
void r1ne(text txt)
{
	/* Стартуем с начальной строки текста */

	node *current = txt->begin;
	current->contents[MAXLINE] = '\0';
	txt->begin = current->next;
	while (current){
		current->previous = current;
		if (txt->cursor->line == current->previous)
			txt->cursor->line = current;
		current = current->next;
		
		}
	txt->length--;
}
