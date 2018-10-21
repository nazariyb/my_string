#include <stddef.h>

//
// Created by arattel on 20.10.18.
//
typedef struct my_str_t my_str_t;
struct my_str_t
{
    size_t capacity_m; // Розмір блока
    size_t size_m;     // Фактичний розмір стрічки
    char*  data;       // Вказівник на блок пам'яті
};

int my_str_getc(const my_str_t* str, size_t index);

int my_str_getc(const my_str_t* str, size_t index){
    if(index >= str->size_m){
        return -1;
    } else{
        return (int) *(str->data + index);
    }
}

