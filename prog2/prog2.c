// команда для компіляції з консолі:
// gcc prog2.c ../library/my_string.c ../library/my_string.h -o prog2test -I ../library

#include <stdio.h>
#include <ctype.h>
#include "my_string.h"

void get_out_file_name(my_str_t* out_file_name, char inp_file_name[]) {
    
    my_str_from_cstr(out_file_name, inp_file_name, 104);
    
    my_str_t txt_str;
    my_str_from_cstr(&txt_str, ".txt", 4);
    
    size_t out_pos = my_str_find(out_file_name, &txt_str, 0);
    my_str_insert_cstr(out_file_name, "_out", out_pos);
    my_str_free(&txt_str);
    
}

int main(int argc, char *argv[]) {

    FILE* inp_file = fopen(argv[1], "r");
    if (!inp_file) return EXIT_FAILURE;
    
    fseek(inp_file, 0, SEEK_END);
    size_t file_size = ftell(inp_file);
    fseek(inp_file, 0, SEEK_SET);

    my_str_t file_str;
    my_str_create(&file_str, file_size);


    int c_int;
    while ((c_int = getc(inp_file)) != EOF) {
        char c = c_int;

        if ispunct(c) continue;

        if (c == ' ') {
            if (my_str_getlast(&file_str) == ' ') continue;
        }
        my_str_pushback(&file_str, tolower(c));
        
    }
    
    my_str_t out_file_name;
    get_out_file_name(&out_file_name, argv[1]);

    FILE* out_file = fopen(my_str_getdata(&out_file_name), "w");
    fputs(my_str_getdata(&file_str), out_file);

    my_str_free(&out_file_name);
    my_str_free(&file_str);
    fclose(inp_file);
    fclose(out_file);
    return EXIT_SUCCESS;
}