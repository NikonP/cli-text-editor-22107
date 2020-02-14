/**
 * create_text.c -- создает в памяти структуры для представления текста
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Создает новый текстовый объект
 * @returns текст
 */
text create_text()
{  
    text txt;

    /* Создаем структуру описания текста */
    if ((txt = (list *) malloc(sizeof(list))) == NULL) {
        fprintf(stderr, "Not enough memory!\n");
        exit(EXIT_FAILURE);
    }
    
    /* Создаем структуру описания курсора */
    if ((txt->cursor = (crsr *) malloc(sizeof(crsr))) == NULL) {
        fprintf(stderr, "Not enough memory!\n");
        exit(EXIT_FAILURE);
    }    
    
    /* Только что созданный текст не содержит ни одной строки */
    txt->begin = NULL;
    txt->end = NULL;
    txt->length = 0;
    
    /* Курсор не настроен ни на какой символ текста */
    txt->cursor->line = NULL;
    txt->cursor->position = 0;
    
    return txt;
}
