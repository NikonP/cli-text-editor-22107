/**
 * cp.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2020, Filin Nikolay <nfilin@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "common.h"
#include "text/text.h"


void cp(text txt)
{
    /*Смена указателей на строки и вывод на экран*/
    swap(txt);
    show(txt);
}
