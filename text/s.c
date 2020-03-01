/**
 * append_line.c -- функции для добавления строк
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"



/**
 * Добавляет одну строку к тексту
 * @param txt текст
 * @param contents новая строка
 * @returns none
 */
void s(text txt)
{
	int cur = 1;
	node *curnd = txt->cursor->line;
	int curCrs = txt->cursor->position+1;
	
	node *nd = (node *) malloc(sizeof(node));
	node *curnd1 = curnd->next;
	//printf("?%s\n", curnd1->contents);
	nd->next = curnd1;
	
	nd->previous = curnd;

	curnd->next = nd;
		
	nd->next->previous = nd;

	char  str[10000];
	curCrs--;
	char  str1[10000];
	strcpy(str1,curnd->contents);
	int u = 0;
	//printf("!%d\n", curCrs);
	int o = strlen(str1);
	
	for(int i = curCrs; i < o; i++){
		str[u] = str1[i];
		u++;
	}
	
	//strcpy(str1, str1+curCrs);
	
	str[10000-1] = '\0';
	curnd->contents[curCrs] = '\n';
	curnd->contents[curCrs+1] = '\0';
	
	strcpy(nd->contents, str);
	if(txt->cursor->position >= strlen(curnd->contents)-1){
		txt->cursor->line = nd;
		txt->cursor->position = txt->cursor->position - strlen(curnd->contents)+1;
	}
//	printf("?%s\n", nd->next->contents);
//	printf("?%s\n", nd->contents);
	
	txt->length++;
}
