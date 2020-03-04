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


void show(text txt);
void load(text txt, char *filename);
void save(text txt, char *filename);

void showupfirst(text txt);
void showodd(text txt);
void showreveven(text txt);
void showclassified(text txt);
void showwordbeginnings(text txt);

int getlength(text txt);
void mle(text txt);
void plb(text txt);
void y(text txt, char *line);
void ce(text txt);
void shownonempty(text txt);

#define CURSOR_CHAR '|'
char* set_cursor(char* contents, int cursor);

#endif
