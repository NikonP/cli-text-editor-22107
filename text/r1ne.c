/**
 * r1ne.c -- 
 * 
 * Copyright (c) 2020, Kulichenko Daniil <kulichen@petrsu.ru>
 *
 * This code is licensed under a MIT-style license
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
	// Проверяем, содержит ли текст хотябы одну строку
	if(txt->length < 1) { 
		printf("Zero-txt failed\n"); 
	}
	else {
		node *current = txt->begin;
		// Если текст состоит из одной непустой строки
		if ((strlen(current->contents) > 1) && (txt->length == 1)) {
			txt->begin = txt->end = NULL;
			txt->length = 0;
			free(current);	
		}
		else {
			// Если первая строка не пустая и не единственная
			if ((strlen(current->contents) > 1) && (txt->length > 1)) {
				if (txt->cursor->line == txt->begin) txt->cursor->line = current->next;
				free(current);
				txt->begin = current->next;
			} 
			else {
				// Шагаем до непустой строки
				while(current && (strlen(current->contents) == 1)) 
				current = current->next;
				// Если текст состоит из пустых строк == ошибка
				if(!current) {
					printf("No non-empty string\n");
					txt->length++;
				}
				else {
					if(current != txt->end) {	
						if(txt->cursor->line == current) {
							txt->cursor->line = current->next;
							if((long)txt->cursor->position > (long)strlen(current->next->contents)) {
								txt->cursor->position = strlen(current->next->contents);
							}
						}
						current->previous->next = current->next;
						current->next->previous = current->previous;
						free(current);
					}
					else {
						txt->cursor->position = 1;
						txt->cursor->line = txt->end = current->previous;
						current->previous->next = NULL;
						free(current);

					}  
				}
			}
		txt->length--;
		}
	}
}
