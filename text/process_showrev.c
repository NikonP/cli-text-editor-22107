/**
 * process_showrev.c -- реализует выведение строк в обратном порядке
 *
 * Copyright (c) 2020, suDecy <dudnikov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

void process_showrev(
    text txt,
    void (*process)(int index, char *contents, int cursor, void *data),
    void *data
)
{   


     int index = 0;
    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);
    
    /* Стартуем с начальной строки текста */
    node *current = txt->end;
    int cursor_position = -1;
    
    /* К каждой строке текста применяем обработчик */
    while (current) {
        if (txt->cursor->line == current) 
            cursor_position = txt->cursor->position;
        else
            cursor_position = -1;
        process(index, current->contents, cursor_position, data);
        current = current->previous;

    }
}
