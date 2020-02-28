/**
 * move_cursor.c -- перемещает курсор в новую позицию
 *
 * Copyright (c) 2020 Nikon "???" Podgornyi <podgorny@cs.petrsu.ru>
 *                    Roman "Neroe" Nikanorov <nikanoro@cs.petrsu.ru>
 *                    
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

int move_cursor(text txt, int line_num, int cursor_pos) {

        /* Проверяем на наличие строки с данным номером */
    if (line_num < 0) {
	printf("Line numbering starts at 0\n");
	return 0;
    }
    if (line_num > (int) txt->length - 1) {
	printf("No line with this number\nLast number: %d\n", (int) txt->length - 1);
	return 0;
    }
    
    node* line = get_line(txt, line_num);
    if(line == NULL) {
        txt->cursor->line = txt->end;
        txt->cursor->position = strlen(txt->end->contents);
        return FAILED_NO_LINE;
    }

    unsigned int str_length = strlen(line->contents);

    /* Проверяем на наличие данной позиции в строке */
    if (cursor_pos < 0) {
	printf("Numbering of positions in a line starts from 0\n");
	return 0;
    }
    if (cursor_pos > (int) str_length) {
	printf("There is no such position in the line\nLast position: %d\n", (int) str_length);
	return 0;
    }
    
    if(cursor_pos < 1) {
        cursor_pos = 1;
    } else if((unsigned int) cursor_pos > str_length) {
        cursor_pos = str_length;
    }

    txt->cursor->line = line;
    txt->cursor->position = cursor_pos;

    return SUCCESS;
}
