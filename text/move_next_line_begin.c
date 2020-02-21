#include "_text.h"

int move_next_line_begin(text txt)
{
    if(txt->cursor->line->next) {
        txt->cursor->line = txt->cursor->line->next;
        txt->cursor->position = 0;
        return SUCCESS;
    } else {
        return FAILED_NO_LINE;
    }
}
