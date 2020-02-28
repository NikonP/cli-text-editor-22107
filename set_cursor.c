#include <string.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "text/text.h"
#include <stdio.h>

char* set_cursor(char* contents, int cursor) {
    char* copy = (char*) malloc(sizeof(char) * MAXLINE);

    strcpy(copy, contents);
    strcpy(copy + cursor + 1, contents + cursor);

    if(cursor != 0) {
        copy[cursor - 1] = CURSOR_CHAR;
    } else {
        copy[cursor] = CURSOR_CHAR;
    }

    if(cursor == (int) strlen(copy)) {
        copy[cursor] = '\n';
    }

    return copy;
}
