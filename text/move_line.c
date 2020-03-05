/**
 * move_line.c -- функции для добавления строк
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Меняет позицию строки в тексте
 *
 * @param txt текст
 * @param old_pos старая позиция
 * @param new_pos новая позиция
 * @returns none
 */
void move_line(text txt, int old_pos, int new_pos)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There is no text to work with!\n");
        return;
    }

    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);

    /* Параметры должны попадать в диапазон */
    if ((old_pos < 0 || (size_t)old_pos >= txt->length) ||
        (new_pos < 0 || (size_t)new_pos >= txt->length)) {
        fprintf(stderr, "Incorrect parameters!\n");
        return;
    }

    /* Стартуем с начальной строки текста */
    node *line = txt->begin;
    int index = 0;

    /* Переходим на строку с номером line */
    while (index != old_pos) {
        line = line->next;
        index++;
    }
    
    /* Переназнаечаем указатели */
    
    /* Если старая позиция - и начало, и конец текста */
    if ((line->next == NULL) && (line->previous == NULL)) {
        txt->begin = NULL;
        txt->end = NULL;
    }
    /* Если старая позиция - начало текста */
    if ((line->next != NULL) && (line->previous == NULL)) {
        line->next->previous = NULL;
        txt->begin = line->next;
    }
    /* Если старая позиция - конец текста */
    if ((line->next == NULL) && (line->previous != NULL)) {
        line->previous->next = NULL;
        txt->end = line->previous;
    }
    /* Если старая позиция не начало и не конец */
    if ((line->next != NULL) && (line->previous != NULL)) {
        line->next->previous = line->previous;
        line->previous->next = line->next;
    }

    /* Стартуем с начальной строки текста */
    node *current = txt->begin;
    index = 0;

    /* Переходим на строку с номером line */
    while (index != new_pos) {
        current = current->next;
        index++;
    }
    
    /* Переназначиваем указатели */
    
    /* Если новая позиция не начало и не конец */
    if ((current != NULL) && (current != txt->begin)) {
        line->next = current;
        line->previous = current->previous;
        current->previous->next = line;
        current->previous = line;
    }
    /* Если новая позиция - конец текста */
    if ((txt->end != NULL) && (current == NULL)) {
        line->previous = txt->end;
        line->next = NULL;
        txt->end->next = line;
        txt->end = line;
    }
    /* Если новая позиция - начало текста */
    if ((txt->begin != NULL) && (current == txt->begin)) {
        line->next = txt->begin;
        line->previous = NULL;
        txt->begin->previous = line;
        txt->begin = line;
    }
    /* Если новая позиция - и начало, и конец текста */
    if ((txt->end == NULL) && (txt->begin == NULL)) {
        line->previous = NULL;
        txt->begin = line;
        line->next = NULL;
        txt->end = line;
    }
}
