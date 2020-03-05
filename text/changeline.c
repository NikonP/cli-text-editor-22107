#include "_text.h"

void changeline(node* line, text txt){
    if(line->next != NULL && line->previous != NULL){
	line->next->previous = line->previous;
	line->previous->next = line->next;
	line->previous = line->next;
	if(line->next->next != NULL){
	    line->next = line->next->next;
	    line->next->previous->previous = line;
	}
	else line->next = NULL;
	line->previous->next = line;



    }

    if(line->next != NULL && line->previous == NULL){
	line->previous = line->next;
	line->next = line->next->next;
	line->next->previous = line;
	line->previous->previous = NULL;
	line->previous->next = line;
	txt->begin = line->previous;
    }
}
