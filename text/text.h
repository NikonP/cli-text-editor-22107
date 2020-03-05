/**
0;136;0c * text.h -- внешний интерфейс библиотеки для работы с текстом
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef TEXT_H
#define TEXT_H

#define MAXLINE 255

/**
 * Коды возврата для функций библиотеки text
 */
#define SUCCESS 0
#define FAILED_NO_LINE 1

/**
 * Абстрактный тип текстовых объектов
 */
typedef struct _list *text;

/**
 * Абстрактный тип курсора
 */
typedef struct _crsr *cursor;


/**
 * Создает новый текстовый объект
 * @returns текст
 */
text create_text();

/**
 * Добавляет одну строку к тексту
 * @param txt текст
 * @param contents новая строка
 * @returns none
 */
void append_line(text txt, const char *contents);


/**
 * Обрабатывает текст, применяя заданную функцию к каждой строке
 *
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void process_forward(
    text txt,
    void (*process)(int index, char *contents, int cursor_position, void *data),
    void *data
);

void process_backward(
    text txt,
    void (*process)(int index, char *contents, int cursor_position, void *data),
    void *data
);


/**
 * Удаляет весь текст
 *
 * @param txt текст
 * @returns none
 */
void remove_all(text txt);

/**
 * Перемещаем курсор в заданную позицию
 * @param txt текст
 * @param line_num номер строки
 * @param cursor_pos номер позиции в строке
 * @returns код исполнения
 */
int m(text txt, int line_num, int cursor_pos);

int move_next_line_begin(text txt);
int add_line_after(text txt, int line_number, char* to_add);
int mp(text txt, int arg1);
void s(text txt);
void r1ne(text txt);
int j(text txt);
void y_line(text txt, const char *contents);
void line_to_end(text txt);
void mwbb(text txt);
void rc(text txt);
void rightcdel(text txt);
void get_current(
    text txt,
    void (*process)(int index, char *contents, int cursor, void *data),
    void *data
    );
void move_line(text txt, int old_pos, int new_pos);
void add_begin(text txt, char* newline);
void pn(text txt, char* mystring);
void move(
    text txt,
    int line_cursor,
    int position_cursor
    );

#endif
