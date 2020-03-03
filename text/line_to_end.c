/**
 * line_to_end.c -- функции перемещения текущей строки в конец
 * 
 * Copyright (c) 2020, Harichev Evgeny <harichev@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"
/**
 * Перемещает текущую строку в конец текста
 * @param txt текст
 * @returns none
 */
void line_to_end(text txt) {

    node *current = txt->cursor->line;
    
   /* Случай, когда текущая строка - начало текста */
   if(current == txt->begin) {
	txt->begin = current->next; // Начало текста теперь следующая строка
	txt->begin->previous = NULL; // Предыдущей строки теперь нет
	append_line(txt, current->contents); // Переносим строку в конец
	}
   else {
      if(current != txt->end) { 
	   /* Редактирование связей, чтобы убрать текущую строку из списка */
	   current->previous->next = current->next; 
	   current->next->previous = current->previous;
 	   append_line(txt, current->contents); // Переносим строку в конец
	   }
	}
   free(current);
   txt->length--;
}



