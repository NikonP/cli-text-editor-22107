/**
 * _text.h -- внутренние структуры представления текста
 * 
 * Этот файл не должен включаться в клиентские модули
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef _TEXT_H
#define _TEXT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "text.h"

/**
 * @struct 
 * @brief Представление одной строки текста как элемента линейного списка
 * 
 */
typedef struct _node {
    char contents[MAXLINE + 1]; /**< содержимое строки текста */
    struct _node *previous;     /**< указатель на предыдущую строку */
    struct _node *next;         /**< указатель на следующую строку */
} node;


/**
 * @struct 
 * @brief Представление курсора
 * 
 */
typedef struct _crsr {
    struct _node *line;         /**< указатель на строку с курсором */
    int position;               /**< позиция курсора в строке */
} crsr;


/**
 * @struct 
 * @brief Линейный двунаправленный список строк текста
 * 
 */
typedef struct _list {
    size_t length;              /**< число строк текста */
    struct _node *begin;        /**< указатель на первую строку текста */
    struct _node *end;          /**< указатель на последнюю строку текста */
    struct _crsr *cursor;       /**< позиция в тексте, курсор */
} list;

typedef struct _list *text;

#endif
