/**
 * process_mcb.c -- реализует сдвиг курсора на одну позицию влево, если это возможно
 *
 * Copyright (c) 2020, suDecy <dudnikov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

void process_mcb(text txt)
//Передвигает курсор на одну позицию влево
{
 if (txt -> cursor -> position > 0)
     txt -> cursor -> position--;;

}
