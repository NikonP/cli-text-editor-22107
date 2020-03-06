#include "_text.h"

void cb(text txt)
{
    node *line = txt->cursor->line;
    node *list1 = txt->begin;
    node *list2 = line->previous;
    node *list3 = line;
    node *list4 = line->next;
    
    if(list1 != list3) {
	list3->previous = NULL;
	list3->next = list1;
	list1->previous = list3;
	if (list1->next == list3) list1->next = list4;
	list2->next = list4;
	if (list4) list4->previous = list2;
	if (list3 == txt->end) txt->end = list2;
	txt->begin = list3;
    }
}
