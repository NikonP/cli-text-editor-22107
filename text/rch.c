#include <stdio.h>
#include <assert.h>
#include "_text.h"

void rightcdel(text txt){
    int i = txt->cursor->position;
    node* cur = txt->cursor->line;
    for(int j = i - 1; cur->contents[j] != '\0'; j++){
	cur->contents[j] = cur->contents[j + 1];
    }
}
