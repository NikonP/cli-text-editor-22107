#include "_text.h"
#include<string.h>
void pn(text txt, char* mystring)
{
       
	node *curnd = txt->cursor->line;

	node *nd = (node *) malloc(sizeof(node));
	node *curnd1 = curnd->next;

	nd->next = curnd1;
	
	nd->previous = curnd;

	curnd->next = nd;	
	if(curnd != txt->end)
		nd->next->previous = nd;
	else
		txt->end = nd;
	strcpy(nd->contents, mystring);
	strcat(nd->contents, "\n");
	txt->length++;
}
