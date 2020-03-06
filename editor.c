/**
 * editor.c -- строковый текстовый редактор
 *
 * Copyright (c) 2020, Alexander Borodin <aborod@petrsu.ru>
 *                     Nikon Podgorny <podgorny@cs.petrsu.ru>
 *                     and others from gr. 22107 (add your name if you want)
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text/text.h"
#include "common.h"

#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    char *second_arg;

    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Вывод сообщения о командах */
    printf("\nEnter help for instructions\n");

    /* Цикл обработки команд */
    while (1) {
        printf("\ned > ");

        /* Получаем команду */
        fgets(cmdline, MAXLINE, stdin);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
	
	/* Базовые команды */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
	}
	
        if (strcmp(cmd, "help") == 0) {
	    FILE *in = fopen("commands.txt", "r");
	    while (fgets(cmdline, MAXLINE, in))
		printf("%s", cmdline);
	    fclose(in);
            continue;
        }
	
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
	    continue;
        }

        if (strcmp(cmd, "save") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: save filename\n");
            } else {
                save(txt, arg);
            }
            continue;
        }

        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }

	if(strcmp(cmd, "m") == 0) {
	    arg = strtok(NULL, " \n");
	    second_arg = strtok(NULL, " \n");
            if (arg == NULL || second_arg == NULL) {
                fprintf(stderr, "Usage: m line_number position\n");
            } else {
		m(txt, atoi(arg), atoi(second_arg));
		show(txt);
            }
            continue;
        }

	/* Команды типа show */
	if (strcmp(cmd, "showrev") == 0) { showrev(txt); continue; }
	if (strcmp(cmd, "showfirstwords") == 0) { showfirstwords(txt); continue; }
	if (strcmp(cmd, "shownonempty") == 0) { shownonempty(txt); continue; }
        if (strcmp(cmd, "showupper") == 0) { showupper(txt); continue; }
	if (strcmp(cmd, "showupfirst") == 0) { showupfirst(txt); continue; }
	if (strcmp(cmd, "showodd") == 0) { showodd(txt); continue; }
        if (strcmp(cmd, "showreveven") == 0) { showreveven(txt); continue; }
	if (strcmp(cmd, "showdigitsonly") == 0){ showdigitsonly(txt); continue; }
	if (strcmp(cmd, "showalphaonly") == 0) { showalpha(txt); continue; }
	if (strcmp(cmd, "showclassified") == 0) { showclassified(txt); continue; }
	if (strcmp(cmd, "shownumspaces") == 0) { shownumspaces(txt); continue; }
	if (strcmp(cmd, "showtrimmedfromstart") == 0) { showtrimmedfromstart(txt); continue; }
	if (strcmp(cmd, "showlastnonspace") == 0) { showlastnonspace(txt); continue; }
	if (strcmp(cmd, "showwordbeginnings") == 0) { showwordbeginnings(txt); continue; }

	/* Вторые команды */
	if (strcmp(cmd, "mcb") == 0) { mcb(txt); continue; }
	if (strcmp(cmd, "mwef") == 0) { mwef(txt); continue; }
	if (strcmp(cmd, "mwbb") == 0) { mwbb(txt); continue; }
	if (strcmp(cmd, "mlb") == 0) { mlb(txt); continue; }
        if (strcmp(cmd, "mle") == 0) { mle(txt); continue; }

	if (strcmp(cmd, "mp") == 0) {
	    arg = strtok(NULL, " \n");
	    if (arg == NULL) {
                fprintf(stderr, "Usage: mp position\n");
            } else {
		mp(txt, atoi(arg));
            }
            continue;
        }
	
        if(strcmp(cmd, "mnlb") == 0) {
            int status = move_next_line_begin(txt);
            switch (status) {
                case SUCCESS:
                    break;
                case FAILED_NO_LINE:
                    fprintf(stderr, "Next line didn't exist\n");
                    break;
                default:
                    fprintf(stderr, "Unhandled error!\n");
                    exit(EXIT_FAILURE);
                    break;
            }
            continue;
        }
	
	if (strcmp(cmd,"mklb")==0){
	    if ((arg = strtok(NULL, " \n")) == NULL){
		fprintf(stderr,"Usage: line number\n");
		continue;
	    }
	    mklb(txt, atoi(arg));
	    continue;
	}

        if (strcmp(cmd, "ple") == 0) { pr_righter(txt); continue; }
	if (strcmp(cmd, "plb") == 0) { plb(txt); continue; }
	if (strcmp(cmd, "rch") == 0) { rightcdel(txt); continue; }
	if (strcmp(cmd, "rle") == 0) { rle(txt); continue; }

        if (strcmp(cmd, "i") == 0) {
            char *addstr = cmd + strlen(cmd) + 1;
            if (addstr[strlen(addstr) - 1] == '\n')
                addstr[strlen(addstr) - 1] = '\0';
            if (*addstr == '\0') {
                fprintf(stderr, "Usage: i textstring\n");
            } else {
                insert(txt, addstr);
            }
            continue;
        }

	if (strcmp(cmd, "y") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: y line\n");
            } else {
                y(txt, arg);
            }
            continue;
        }	

	/* Третьи команды */
        if (strcmp(cmd, "rt") == 0) { rt(txt); continue; }
	if (strcmp(cmd, "rc") == 0) { rc(txt); continue; }
	if (strcmp(cmd, "r1e") == 0) { r1e(txt); continue; }
        if (strcmp(cmd, "r1ne") == 0) { r1ne(txt); continue; }
	if (strcmp(cmd, "j") == 0) { j(txt); continue; }

        if(strcmp(cmd, "p") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: p line text\n");
            } else {
                if ((second_arg = strtok(NULL, "\0")) == NULL) {
                    fprintf(stderr, "Usage: p line text\n");
                } else {
                    int status = add_line_after(txt, atoi(arg), second_arg);
                    switch (status) {
                        case SUCCESS:
                            break;
                        case FAILED_NO_LINE:
                            fprintf(stderr, "No line with number %d\n", atoi(arg));
                            break;
                        default:
                            fprintf(stderr, "Unhandled error!\n");
                            exit(EXIT_FAILURE);
                            break;
                    }
                }
            }
            continue;
        }

      	if (strcmp(cmd, "pn") == 0) {
	    if ((arg = strtok(NULL, "\n")) == NULL){
		fprintf(stderr,"Usage: line\n");
		continue;
	    } 
	    pn(txt, arg);
            continue;
	}

        if (strcmp(cmd, "p1") == 0) {
            if ((arg = strtok(NULL, "\n")) == NULL) {
                fprintf(stderr, "Usage: p1 <string>\n");
		continue;
            }
            strcat(arg, "\n");
            place_first(txt, arg);
            continue;
        }

	if (strcmp(cmd, "s") == 0) { s(txt); continue; }
	if (strcmp(cmd, "cn") == 0) { cn(txt); show(txt); continue; }
	if (strcmp(cmd, "cp") == 0) { cp(txt); show(txt); continue; }		
        if (strcmp(cmd, "cb") == 0) { cb(txt); show(txt); continue; }
        if (strcmp(cmd, "ce") == 0) { ce(txt); continue; }

        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
