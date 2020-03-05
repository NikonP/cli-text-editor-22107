#include <stdio.h>
#include <assert.h>
#include "_text.h"

void rightcdel(text txt){
    int j, i = txt->cursor->position;
    node* cur = txt->cursor->line;
    if (cur->contents[i] != '\n') {
	for(j = i; cur->contents[j + 1] != '\0'; j++){
	    cur->contents[j] = cur->contents[j + 1];
	}
	cur->contents[j] = '\0';
    }
}
