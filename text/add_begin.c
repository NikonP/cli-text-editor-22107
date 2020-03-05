#include "_text.h"

void add_begin(text txt, char* newline)
{
    append_line(txt, newline);

    node *tmp = txt->end->previous;

    txt->end->next = txt->begin;
    txt->end->previous = NULL;
    txt->begin->previous = txt->end;
    txt->end = tmp;
    txt->begin = txt->begin->previous;
    txt->end->next = NULL;
}
