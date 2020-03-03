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
   /* Случай, когда текущая строка - начало текста */
   if(txt->cursor->line == txt->begin) {
	txt->begin = txt->cursor->line->next; // Начало текста теперь следующая строка
	append_line(txt, txt->cursor->line->contents); // Переносим строку в конец
	}
   else {
      if(txt->cursor->line!=txt->end) { 
	   /* Редактирование связей, чтобы убрать текущую строку из списка */
	   txt->cursor->line->previous->next = txt->cursor->line->next; 
	   txt->cursor->line->next->previous = txt->cursor->line->previous;
 	   append_line(txt, txt->cursor->line->contents); // Переносим строку в конец
	   }
	}
}



