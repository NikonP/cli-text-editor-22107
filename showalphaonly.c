#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void showalphaonly(int index, char *contents, int cursor, void *data);

void showalpha(text txt)
{
    process_forward(txt, showalphaonly, NULL);
}

static void showalphaonly(int index, char *contents, int cursor, void *data)
{
    assert(contents != NULL);

    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);

    int i = 0;

    /* Проверяем, буквенный ли символ */
    while(contents[i] != '\0') {
        if ((contents[i] > 64 && contents[i] < 96) || (contents[i] > 96 && contents[i] < 123)) {
            printf("%c", contents[i]);
        } else {
	    printf(" ");
	}
        ++i;
    }

    printf("\n");

}
