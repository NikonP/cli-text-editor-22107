/**
 * j.c -- объединяет строку с курсором со следующей
 *
 * Copyright (c) 2020 Roman "Neroe" Nikanorov <nikanoro@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

int j(text txt)
{
    /* Объявляем используемые переменные */
    int i;
    
    /* Проверяем на последнюю строку */
    if (txt->cursor->line->next == NULL) {
	printf("Ошибка: это последняя строка\n");
	return 0;
    }

    /* Удаляем символ перевода строки */
    for (i = 0; txt->cursor->line->contents[i] != '\n'; i++);
    txt->cursor->line->contents[i] = ' ';

    /* Прикрепляем следующую строку */
    strcat(txt->cursor->line->contents, txt->cursor->line->next->contents);

    /* Меняем связи */
    if (txt->cursor->line->next->next != NULL) {
	txt->cursor->line->next->next->previous = txt->cursor->line;
	txt->cursor->line->next = txt->cursor->line->next->next;
    } else {
	txt->cursor->line->next = NULL;
    }
    return 0;
}
