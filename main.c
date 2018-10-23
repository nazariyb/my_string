#include <stdio.h>
#include <stdlib.h>
#include<string.h>


typedef struct {
    size_t capacity_m; // Розмір блока
    size_t size_m;     // Фактичний розмір стрічки
    char *data;       // Вказівник на блок пам'яті
} my_str_t;

size_t str_len(my_str_t *str) {
    size_t i = 0;
    while (str->data[++i]) {
    }
    return i;
}

int my_str_empty(const my_str_t *str) {
    return (str->size_m) ? 0 : 1;
}

// not finished yet
int my_str_from_cstr(my_str_t *str, char *cstr, size_t buf_size) {
    str->capacity_m = buf_size + 1;
//    str->size_m = str_len(cstr);
    str->data = cstr;
    return 0;
}

int my_str_create(my_str_t *str, size_t buf_size) {
    if (str != NULL) {
        char *allocatedMemory = malloc(buf_size + 1);
        if (allocatedMemory) {
            str->data = allocatedMemory;
            str->capacity_m = buf_size;
            str->size_m = 0;
            str->data[0] = '\0';
            return 0;
        }
    }
    return -1;
}

size_t my_str_size(const my_str_t *str) {
    return str->size_m;
}

void my_str_free(my_str_t *str) {
    free(str->data);
}

size_t my_str_capacity(const my_str_t *str) {
    return str->capacity_m;
};

int my_str_getc(const my_str_t* str, size_t index);
int my_str_putc(my_str_t* str, size_t index, char c);
int my_str_pushback(my_str_t* str, char c);
int my_str_popback(my_str_t* str);
void print(const my_str_t* str);
int my_str_copy(const my_str_t* from, my_str_t* to, int reserve);



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
        char symbol = str->data[i];
        printf("%c", symbol);
    }
    printf("\n");
}


int my_str_copy(const my_str_t* from, my_str_t* to, int reserve){
    if(reserve) {
        my_str_create(to, from->capacity_m);
    } else{
        my_str_create(to, from->size_m);
    }
    for(int i = 0; i < from->size_m; i++){
        to->data[i] = from->data[i];
    }
    to->data[to->size_m + 1] = '\0';
}
//! Очищає стрічку -- робить її порожньою. Складність має бути О(1).
void my_str_clear(my_str_t* str){
    my_str_create(str, str->capacity_m);
}

//! Вставити символ у стрічку в заданій позиції, змістивши решту символів праворуч.
//! Якщо це неможливо, повертає -1, інакше 0.
int my_str_insert_c(my_str_t* str, char c, size_t pos){
    if(pos > str->size_m || pos >= str->capacity_m || (str->size_m + 1) > str->capacity_m){
        return -1;
    } else{
        if(pos == str->size_m){
            str->data[str->size_m] = c;
            str->data[str->size_m + 1] = '\0';
        } else{
            size_t i = (str->size_m);
            while(i-- > pos){
                str->data[i + 1] = str->data[i];
            }
            str->data[pos] = c;
            str->size_m++;
        }
        return 0;
    }
}
//! Вставити стрічку в заданій позиції, змістивши решту символів праворуч.
//! Якщо це неможливо, повертає -1, інакше 0.
int my_str_insert(my_str_t* str, const my_str_t* from, size_t pos){
   if(str->size_m + from->size_m > str->capacity_m || pos > str->size_m){
       return -1;
   } else{
       if(pos < str->size_m) {
           move_on(str, pos, from->size_m);
           size_t i = pos;
           while (i - pos < from->size_m) {
               str->data[i] = from->data[i - pos];
               i++;
           }
       }else if(pos == str->size_m){
           str->data[str->size_m] = NULL;
           str->size_m += from->size_m;
           str->data[str->size_m + 1] = '\0';
           size_t i = pos;
           while (i - pos < from->size_m) {
               str->data[i] = from->data[i - pos];
               i++;
           }
       }
       return 0;
   }
}
void move_on(my_str_t* str, int start_pos, int gap){
    size_t old_size = str->size_m;
    str->size_m += gap;
    str->data[old_size] = NULL;
    str->data[str->size_m] = '\0';
    int i = old_size;
    while (i-->=start_pos){
        str->data[i + gap] = str->data[i];
    }
}
//! Вставити C-стрічку в заданій позиції, змістивши решту символів праворуч.
//! Якщо це неможливо, повертає -1, інакше 0.
int my_str_insert_cstr(my_str_t* str, const char* from, size_t pos){
    size_t string_size = strlen(from);
    if(str->size_m + string_size > str->capacity_m || pos > str->size_m){
        return -1;
    } else{
        if(pos < str->size_m){
            move_on(str, pos, string_size);
            size_t i = pos;
            while (i - pos < string_size) {
                str->data[i] = from[i - pos];
                i++;
            }
        }else if(pos == str->size_m){
            str->data[str->size_m] = NULL;
            str->size_m += string_size;
            str->data[str->size_m + 1] = '\0';
            size_t i = pos;
            while (i - pos < string_size) {
                str->data[i] = from[i - pos];
                i++;
            }
        }
        return 0;

    }
}

//! Додати стрічку в кінець.
//! Якщо це неможливо, повертає -1, інакше 0
int my_str_append(my_str_t* str, const my_str_t* from){
    my_str_insert(str, from, str->size_m);
}
//! Порівняти стрічки, повернути 0, якщо рівні (за вмістом!)
//! -1, якщо перша менша, 1 -- якщо друга.
//! Поведінка має бути такою ж, як в strcmp.

int my_str_cmp(my_str_t* str, const char* from){
    for(size_t i = 0; i < str->size_m + 1; i++){
        if(str->data[i] < from[i]){
            return -1;
        } else if(str->data[i] > from[i]){
            return 1;
        } else{
            if(str->data[i] == '\0'){
                return 0;
            }
        }
    }
}
//! Скопіювати підстрічку, із beg включно, по end не включно ([beg, end)).
//! Якщо end виходить за межі str -- скопіювати скільки вдасться, не вважати
//! це помилкою. Якщо ж в ціловій стрічці замало місця, або beg більший
//! за розмір str -- це помилка. Повернути відповідний код завершення.
int my_str_substr(const my_str_t* str, my_str_t* to, size_t beg, size_t end){
    if(end - beg + 1 > to->capacity_m || beg >= str->size_m){
        return -1;
    } else{
        my_str_clear(to);
        size_t slice_size;
        size_t  end_index;
        if(end < str->size_m){
            slice_size = end - beg;
            end_index = end;
        } else{
            slice_size = str->size_m - beg;
            end_index = str->size_m;
        }
        to->size_m = slice_size;
        to->data[slice_size] = '\0';
        for(size_t  i = beg; i < end_index; i++){
            to->data[i - beg] = str->data[i];
        }
        return 0;
    }
}
//! Повернути вказівник на С-стрічку, еквівалентну str.
//! Вважатимемо, що змінювати цю С-стрічку заборонено.
//! Якщо в буфері було зарезервовано на байт більше за макс. розмір, можна
//! просто додати нульовий символ в кінці та повернути вказівник data.
const char* my_str_get_cstr(my_str_t* str){
    return str->data;
}

void main(){
    my_str_t test_str;
    my_str_create(&test_str, 200);
    my_str_pushback(&test_str, 'a');
    my_str_pushback(&test_str, 'f');
    my_str_pushback(&test_str, 'k');
    my_str_t test1;
    my_str_create(&test1, 120);
    my_str_pushback(&test1, 'x');
    my_str_pushback(&test1, 'y');
    my_str_pushback(&test1, 'i');
    my_str_append(&test_str, &test1);
    print(&test_str);
    my_str_substr(&test_str, &test1, 2, 38);
    char *str = my_str_get_cstr(&test_str);
    printf("%i\n", strlen(str));
    printf("%s\n", str);
    print(&test1);
}
