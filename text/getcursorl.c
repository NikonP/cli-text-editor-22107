#include <stdio.h>
#include <assert.h>
#include "_text.h"

node* getcursorl(text txt){
    return txt->cursor->line;
}
