/**
 * m.c -- перемещает курсор в новую позицию
 *
 * Copyright (c) 2020 Roman "Neroe" Nikanorov <nikanoro@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

int m(text txt, int arg1, int arg2)
{
    /* Проверяем на наличие строки с данным номером */
    if (arg1 < 0) {
        printf("Line numbering starts at 0\n");
        return 0;
    }

    if (arg1 > (int) txt->length - 1) {
        printf("No line with this number\nLast number: %d\n", (int) txt->length - 1);
        return 0;
    }

    /* Указатель на новую строку с курсором */
    node* current = txt->begin;

    /* Смещаем указатель до нужной строки */
    for (int i = 0; i < arg1; i++) {
        current = current->next;
    }

    /* Проверяем на наличие данной позиции в строке */
    if (arg2 < 0) {
        printf("Numbering of positions in a line starts from 0\n");
        return 0;
    }
    if (arg2 > (int) strlen(current->contents) - 1) {
        printf("There is no such position in the line\nLast position: %d\n", (int) strlen(current->contents) - 1);
        return 0;
    }

    /* Новая строка курсора */
    txt->cursor->line = current;

    /* Новая позиция курсора в строке */
    txt->cursor->position = arg2;

    return 0;
}
