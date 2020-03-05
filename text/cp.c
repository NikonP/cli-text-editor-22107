#include "_text.h"

void cp(text txt)
{   
    node *line = txt->cursor->line;
    node *list1 = NULL;
    node *list2 = line->previous;
    node *list3 = line;
    node *list4 = line->next;
    if (list2) list1 = list2->previous;
    
    if(list2) {
	list2->previous = list3;
	list2->next = list4;
	list3->previous = list1;
	list3->next = list2;
	if (list1) list1->next = list3;
	else txt->begin = list3;
	if (list4) list4->previous = list2;
	else txt->end = list2;
    }
}
