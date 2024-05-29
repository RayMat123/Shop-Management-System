#include "utils.h"

int get_str_len(const char* source){
    int len = 0;

    while(*source != '\0'){
        len++;
        source++;
    }

    return len;
}

char* size_alloc(const char* source, char* dest){
    int size = get_str_len(source);

    dest = new char[size + 1];

    return dest;
}

void copy_str(char *&dest, char *source){
    dest = size_alloc(source, dest);

    char* destPtr = dest;

    while(*source != '\0'){
        *destPtr = *source;
        *source++;
        *destPtr++;
    }

    *destPtr = '\0';
}