/**
 * ce.c -- команда переноса текущей строки в конец текста
 *
 * Copyright (c) 2020, Harichev Evgeny <harichev@cs.karelia.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include "common.h"
#include "text/text.h"

void ce(text txt){
    /* Переносим строку в конец текста */
    line_to_end(txt);
    /* выводим текст */
    show(txt);
    }
