//
// Created by 3naza on 10/25/2018.
//
// команда для компіляції з консолі:
// gcc prog2.c ../library/my_string.c ../library/my_string.h -o prog2test -I ../library

#include <stdio.h>
#include "my_string.h"

int main(int argc, char *argv[]) {
    FILE* inp_file = fopen(argv[1], "r");
    if (!inp_file) return EXIT_FAILURE;
    my_str_t file_str;
    my_str_create(&file_str, 1000);
    char file_cstr[1000];
    // char file_cstr2[1000];
    // while (fscanf(inp_file, " %s", file_cstr)) {
        // printf("%s\n", file_cstr);
        // my_str_append_cstr(&file_str, file_cstr);
        
    // }
    // int res2 = fscanf(inp_file, " %s", file_cstr2);
    printf("%s\n", file_str.data);
}