#include <stdio.h>
#include "common.h"
#include "text/text.h"

void place_first(text txt, char* line)
{
    add_begin(txt, line);
    show(txt);
}
