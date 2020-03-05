#include "_text.h"

void cn(text txt)
{   
    node *line = txt->cursor->line;
    node *list1 = line->previous;
    node *list2 = line;
    node *list3 = line->next;
    node *list4 = NULL;
    if (list3) list4 = list3->next;
    
    if(list3) {
	list3->previous = list1;
	list3->next = list2;
	list2->previous = list3;
	list2->next = list4;
	if (list1) list1->next = list3;
	else txt->begin = list3;
	if (list4) list4->previous = list2;
	else txt->end = list2;
    }
}
