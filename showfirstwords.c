/**
 * showfirstwords.c -- вывод первых слов строк на экран
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

static void showf_words(int index, char *contents, int cursor, void *data);
int flag = 1;
/**
 * Выводит содержимое указанного файла на экран
 */
void showfirstwords(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, showf_words, NULL);
}



static void showf_words(int index, char *contents, int cursor, void *data)
{

    UNUSED(cursor);
    UNUSED(data);
    UNUSED(index);
    
    int flag_enter = flag;
    int length = strlen(contents);
    for(int i = 0; i < length; i++){
        if(flag_enter){
            /* Skip empty space */
            while(contents[i] == ' '){
                i++;
            }
            
            int flag_exit = 1;
            while(flag_exit){
                switch(contents[i]){
                    case ' ':
                        flag_enter = 0;
                        flag_exit = 0;
                        printf("\n");
                        break;
                    case '\n':
                        flag_enter = 1;
                        flag_exit = 0;
                        printf("\n");
                        break;
                    default:
                        printf("%c", contents[i]);
                        if(i + 1 < length){
                            i++;
                        } else {
                            flag_exit = 0;
                            flag_enter = 1;
                        }
                        break;
                }
            }
        }
        
        if(contents[i] == '\n'){
            flag_enter = 1;
        }
    }
    
    flag = flag_enter;
    
}
