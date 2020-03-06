/**
 * mwef_text.c
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "_text.h"

void mwef_text(text txt){
    
    node* current = txt->begin;
    while(current != txt->cursor->line){
        current = current->next;
    }
    
    int length = strlen(current->contents);
    while(
        current->contents[txt->cursor->position] != ' ' 
        && current->contents[txt->cursor->position] != '.'
        && current->contents[txt->cursor->position] != ','
        && current->contents[txt->cursor->position] != '\n' 
        && txt->cursor->position < length){
        
        txt->cursor->position++;
    }
    
    if(txt->cursor->position == length){
        current = current->next;
        int length = strlen(current->contents);
        
        while(
        current->contents[txt->cursor->position] != ' ' 
        && current->contents[txt->cursor->position] != '.'
        && current->contents[txt->cursor->position] != ','
        && current->contents[txt->cursor->position] != '\n' 
        && txt->cursor->position < length){
        
        txt->cursor->position++;
    }
    }
    
}
