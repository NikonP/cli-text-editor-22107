/**
 * rt.c -- реализует команду удаления нижней строки
 *
 * Copyright (c) 2020, suDecy <dudnikov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"


void rt(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_rt(txt);
}

