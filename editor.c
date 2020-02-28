/**
 * editor.c -- строковый текстовый редактор
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
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

        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }

	/* Список команд */
        if (strcmp(cmd, "help") == 0) {
	    FILE *in = fopen("commands.txt", "r");
	    while (fgets(cmdline, MAXLINE, in))
		printf("%s", cmdline);
	    fclose(in);
            continue;
        }
	
        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "save") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: save filename\n");
            } else {
                save(txt, arg);
            }
            continue;
        }

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }

	/* Выводим текст, опуская чётные строки */
        if (strcmp(cmd, "showodd") == 0) {
            showodd(txt);
            continue;
        }
	
        if(strcmp(cmd, "showreveven") == 0) {
            showreveven(txt);
            continue;
        }

        if(strcmp(cmd, "m") == 0) {
	    arg = strtok(NULL, " \n");
	    second_arg = strtok(NULL, " \n");
            if (arg == NULL || second_arg == NULL) {
                fprintf(stderr, "Usage: m line_number position\n");
            } else {
		move_cursor(txt, atoi(arg), atoi(second_arg));
            }
            continue;
        }

        /* Перемещение курсора в заданную позицию в текущей строке */
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
            move_next_line_begin(txt);
            continue;
        }

	/* Объединяет строку с курсором со следующей */
	if (strcmp(cmd, "j") == 0) {
	    j(txt);
            continue;
        }
	
        if(strcmp(cmd, "p") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: p line text\n");
            } else {
                if ((second_arg = strtok(NULL, "\0")) == NULL) {
                    fprintf(stderr, "Usage: p line text\n");
                } else {
                    add_line_after(txt, atoi(arg), second_arg);
                }
            }
            continue;
        }

        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
