#include <string.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "text/text.h"

char* set_cursor(char* contents, int cursor) {
    char* copy = (char*) malloc(sizeof(char) * MAXLINE);

    strcpy(copy, contents);
    strcpy(copy + cursor + 1, contents + cursor);

    copy[cursor] = CURSOR_CHAR;

    if(cursor == (int) strlen(copy) - 1) {
        copy[cursor + 1] = '\n';
    }

    return copy;
}
