#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/_text.h"

void cn(text txt){
    changeline(getcursorl(txt), txt);
}
