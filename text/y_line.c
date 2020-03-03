/**
 * append_line.c -- функции для добавления строк
 * 
 * Copyright (c) 2020, Harichev Evgeny <harichev@cs.karelia.ru>
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
void y_line(text txt, const char* contents) {
    // строка которую нужно изменить
    node* line = txt->cursor->line;
    unsigned int contents_len = strlen(contents);

    // Проверка на переполнение
    if(txt->cursor->position + contents_len + 1 <= MAXLINE) {
        // Копируем в позицию курсора и далее
        strcpy(line->contents + txt->cursor->position, contents);
        // Все что после новой подстроки обрезаем
        line->contents[txt->cursor->position + contents_len] = '\n';
 	line->contents[txt->cursor->position + contents_len + 1] = '\0';
    	} 
    else { 
	fprintf(stderr, "Too long line!\n"); // Контроль переполнения
        exit(EXIT_FAILURE);  
    	}
}



