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

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);

/**
 * Сохраняет содержимое указанного файла
 */
void save(text txt, char *filename);

/**
 * Выводит содержимое указанного файла на экран в обратном порядке
 * пропуская нечётные строки
 */
void showreveven(text txt);

#define CURSOR_CHAR '|'
char* set_cursor(char* contents, int cursor);

#endif
