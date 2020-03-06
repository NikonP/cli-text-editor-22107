/**
 * common.h -- прототипы функций реализации команд редактора
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/* Стандартные функции */
void load(text txt, char *filename);
void show(text txt);
void save(text txt, char *filename);

/* Функции типа show */
void showrev(text txt);
void shownonempty(text txt);
void showupper(text txt);
void showupfirst(text txt);
void showodd(text txt);
void showreveven(text txt);
void showdigitsonly(text txt);
void showalpha(text txt);
void showclassified(text txt);
void shownumspaces(text txt);
void showtrimmedfromstart(text txt);
void showlastnonspace(text txt);
void showwordbeginnings(text txt);

/* Микс функций */
int getlength(text txt);
void mle(text txt);
void plb(text txt);
void y(text txt, char *line);
void insert(text txt, char *contents);
void ce(text txt);
void pr_righter(text txt);
void place_first(text txt, char* line);
void mklb(text txt,int line);
void mcb(text txt);
void rt(text txt);
void mlb(text txt);
void r1e(text txt);
void rle(text txt);
char* set_cursor(char* contents, int cursor);

/* Символ курсора */
#define CURSOR_CHAR '|'

#endif
