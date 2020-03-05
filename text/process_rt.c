/**
 * process_rt.c -- реализует удаление нижней строки
 *
 * Copyright (c) 2020, suDecy <dudnikov@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */


#include "_text.h"

void process_rt( text txt )
{
//если одна строка в документе, то не выполняем функцию rt
	if (txt->end != txt->begin)
	  {
   	    int flag =0;
   	    node *end_line = txt->end;

   	    if ( txt->end->previous != NULL)
	       {
	         if(txt->cursor->line == txt->end)
                       flag = 1;
	       }

  	    txt->end->previous->next = NULL;

  	    txt->end = txt->end->previous;

//если курсор находится на удаляемой строке, переносим его выше

   	    if ( flag )
     	        txt->cursor->line = txt->end;
	    txt->length--;
	    free( end_line );

	  }
}
