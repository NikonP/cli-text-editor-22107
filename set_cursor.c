#include <string.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "text/text.h"
#include <stdio.h>

char* set_cursor(char* contents, int cursor) {
    char* copy = (char*) malloc(sizeof(char) * MAXLINE);

    int copy_length = (int) strlen(copy);

    strcpy(copy, contents);
    strcpy(copy + cursor, contents + cursor - 1);

    copy[cursor - 1] = CURSOR_CHAR;

    if(cursor == copy_length) {
        copy[cursor + 1] = '\n';
    }

    return copy;
}
