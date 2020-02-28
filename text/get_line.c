#include "_text.h"

node* get_line(text txt, int num) {
    if(txt) {
        node* current_line = txt->begin;
        int current_line_num = 0;
        while(num != current_line_num) {
            if(current_line->next) {
                current_line = current_line->next;
                current_line_num++;
            } else {
                return NULL;
            }
        }
        return current_line;
    } else {
        return NULL;
    }
}
