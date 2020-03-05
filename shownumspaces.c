#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
void count_spaces(int index, char *contents, int cursor, void *data);

void shownumspaces(text txt){
    process_forward(txt, count_spaces, NULL);
}

void count_spaces(int index, char *contents, int cursor, void *data)
{
    UNUSED(index);
    UNUSED(data);
    UNUSED(cursor);

    int sc = 0;
    for(int i = 0; contents[i] != '\0'; i++){
	if(contents[i] == ' ')
	    sc++;
    }
    printf("%d\n", sc);
}
