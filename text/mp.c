/**
 * mp.c -- перемещает курсор в новую позицию в текущей строке
 *
 * Copyright (c) 2020 Roman "Neroe" Nikanorov <nikanoro@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

int mp(text txt, int arg1)
{
    /* Указатель на текущую строку с курсором */
    node* current = txt->begin;
    
    /* Смещаем указатель до нужной строки */
    while (current != txt->cursor->line) {
	current = current->next;
    }

    /* Проверяем на наличие данной позиции в строке */
    if (arg1 < 0) {
	printf("Нумерация позиций в строке начинается с 0\n");
	return 0;
    }
    if (arg1 > (int) strlen(current->contents) - 2) {
	printf("В строке нет такой позиции\nПоследняя позиция: %d\n", (int) strlen(current->contents) - 2);
	return 0;
    }
    
    /* Новая позиция курсора в строке */
    txt->cursor->position = arg1;
    
    return 0;
}
