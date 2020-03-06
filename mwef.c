/**
 * mwef.c перемещение курсора в конец слова
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

void mwef(text txt){
    
    mwef_text(txt);
    show(txt);
    
}
