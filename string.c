#include <stddef.h>
#include <stdio.h>

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
int my_str_putc(my_str_t* str, size_t index, char c);
int my_str_pushback(my_str_t* str, char c);
int my_str_popback(my_str_t* str);
void print(const my_str_t* str);


int my_str_getc(const my_str_t* str, size_t index){
    if(index >= str->size_m){
        return -1;
    } else{
        return (int) str->data[index];
    }
}

int my_str_putc(my_str_t* str, size_t index, char c){
    if(index >= str->size_m){
        return -1;
    } else{
        str->data[index] = c;
        return 0;
    }
}

//! Додає символ в кінець.
//! Повертає 0, якщо успішно, -1, якщо буфер закінчився.
int my_str_pushback(my_str_t* str, char c){
    if((str->size_m + 1) >= str->capacity_m){
        return -1;
    } else{
        str->data[str->size_m] = c;
        str->data[str->size_m + 1] = '\0';
        str->size_m++;
        return 0;
    }
}

int my_str_popback(my_str_t* str){
    if(str->capacity_m < str->size_m){
        return -1;
    } else{
        int symbol = NULL;
        symbol = (int) str->data[str->size_m - 1];
        str->data[str->size_m - 1] = NULL;
        str->size_m -= 1;
        return symbol;
    }
}

void print(const my_str_t* str){
    for(int i = 0; i < str->size_m; i++){
        printf(*(str->data + i) + '\n');
    }
}



