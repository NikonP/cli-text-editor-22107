#include "_text.h"

int rn(text txt, int index)
{
    if (!txt->length) { printf("0 lines\n"); return 0; }
    if (index < 0 || index > (int) txt->length - 1) { printf("No lines with this number\n"); return 0; }
    
    node *line = txt->begin;
    for (int k = 0; k != index; k++, line = line->next); 
    
    node *list1 = line->previous;
    node *list2 = line;
    node *list3 = line->next;
    if (list1) list1->next = list3;
    if (list3) list3->previous = list1;
    if (list2 == txt->begin) txt->begin = list3;
    if (list2 == txt->end) txt->end = list1;
    if (line == txt->cursor->line) { txt->cursor->line = txt->begin, txt->cursor->position = 0; }
    txt->length--;
    free(line);
    return 0;
    
}
