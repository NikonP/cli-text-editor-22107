/**
 * mklb.c -- функция перемещения курсора в начало заданной строки
 * 
 * Copyright (c) 2020, Svetova Kristina  <ksvetova@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"



void mklb(text txt, int line)
{  
    move_cursor(txt, line, 0);
}


