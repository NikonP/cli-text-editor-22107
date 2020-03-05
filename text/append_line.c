/**
 * append_line.c -- функции для добавления строк
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Выделяет память под один элемент списка
 */
static node *create_node(const char *contents);


/**
 * Добавляет одну строку к тексту
 * @param txt текст
 * @param contents новая строка
 * @returns none
 */
void append_line(text txt, const char *contents)
{
    /* Если список пуст, создаем первый элемент */
    if (txt->length == 0) {
        txt->begin = txt->end = create_node(contents);
        txt->length = 1;
    /* иначе добавляем элемент в конец списка */
    } else {
        txt->end->next = create_node(contents);
        txt->end->next->previous = txt->end;
        txt->end = txt->end->next;
        txt->length++;
    }

    /* Устанавливаем курсор в конец добавленной строки */
    txt->cursor->line = txt->end;
    txt->cursor->position = strlen(txt->end->contents) - 1;
}


/*
 * Выделяет память под один элемент списка
 */
static node *create_node(const char *contents)
{
    assert(contents != NULL);

    node *nd;

    unsigned int str_length = strlen(contents);

    if ((nd = (node *) malloc(sizeof(node))) == NULL) {
        fprintf(stderr, "Not enough memory!\n");
        exit(EXIT_FAILURE);
    }

    if (str_length > MAXLINE) {
        fprintf(stderr, "Too long line!\n");
        exit(EXIT_FAILURE);
    }

    strncpy(nd->contents, contents, MAXLINE);
    if (nd->contents[str_length - 1] != '\n') {
        nd->contents[str_length] = '\n';
    }
    nd->contents[MAXLINE] = '\0';
    nd->contents[strlen(contents) + 1] = '\n';
    nd->previous = NULL;
    nd->next = NULL;

    return nd;
}
