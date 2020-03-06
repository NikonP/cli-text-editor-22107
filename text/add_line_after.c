/**
 * add_line_after.c -- вставка новой строки после строки с заданным номеров
 * реализация команды "p номер текст"
 *
 * Copyright (c) 2020, Nikon Podgorny <podgorny@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

static node *create_node(const char *contents);

/**
 * Добавляет одну строку к тексту после строки с указанным номером
 * @param txt текст
 * @param line_number номер после которого нажо вставить строку
 * @param to_add текст новой строки
 * @returns статус
 */
int add_line_after(text txt, int line_number, char* to_add)
{
    node* line = get_line(txt, line_number);

    if(line != NULL) {
        node* new_node = create_node(to_add);

        if(line->next) {
            new_node->next = line->next;
        }

        new_node->previous = line;

        if(line -> next) {
            line->next->previous = new_node;
        }

        line->next = new_node;
        txt->length++;
        return SUCCESS;
    } else {
        return FAILED_NO_LINE;
    }
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
