/**
 * mcb.c -- реализует команду сдвига курсора на одну позицию влево, если это возможно
 *
 * Copyright (c) 2020, suDecy <dudnikov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

void mcb(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_mcb(txt);
}

