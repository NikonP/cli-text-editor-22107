#include "_text.h"

int move_cursor(text txt, int line_num, int cursor_pos) {
    node* line = get_line(txt, line_num);
    if(line == NULL) {
        txt->cursor->line = txt->end;
        txt->cursor->position = strlen(txt->end->contents);
        return FAILED_NO_LINE;
    }

    unsigned int str_length = strlen(line->contents);

    if(cursor_pos < 1) {
        cursor_pos = 1;
    } else if((unsigned int) cursor_pos > str_length) {
        cursor_pos = str_length;
    }

    txt->cursor->line = line;
    txt->cursor->position = cursor_pos;

    return SUCCESS;
}
