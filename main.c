#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct {
    size_t capacity_m; // Розмір блока
    size_t size_m;     // Фактичний розмір стрічки
    char *data;       // Вказівник на блок пам'яті
} my_str_t;

//size_t str_len(my_str_t *str) {
//    size_t i = 0;
//    while (str->data[++i]) {
//    }
//    return i;
//}

char *str_copy(char *destination, char *source)
{
    char *start = destination;

    while(*source)
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';
    return start;
}

size_t str_len(const char *str) {
    size_t len = 1;
    while (*str++) {len++;}
    return len - 1;
}

char* str_cat(char* dest_ptr, const char * src_ptr) {

    char* strret = dest_ptr;
    if(dest_ptr && src_ptr)
    {
        while(*dest_ptr) {
            dest_ptr++;
        }

        while(*src_ptr) {
            *dest_ptr++ = *src_ptr++;
        }
        *dest_ptr = '\0';
    }
    return strret;
}

//! Повертає булеве значення, чи стрічка порожня:
int my_str_empty(const my_str_t *str) {
    return (str->size_m) ? 0 : 1;
}

//! Створити стрічку із буфером вказаного розміру із переданої С-стрічки.
//! Якщо розмір -- 0, виділяє блок, рівний розміру С-стрічки, якщо
//! менший за її розмір -- вважати помилкою.
//! Пам'ять виділяється динамічно.
//! 0 -- якщо все ОК, -1 -- недостатній розмір буфера, -2 -- не вдалося виділити пам'ять
int my_str_from_cstr(my_str_t *str, char *cstr, size_t buf_size) {

    if (str) {
        char *allocatedMemory;
        if (!buf_size) {
            allocatedMemory = malloc(str_len(cstr));
        } else if (buf_size >= str_len(cstr)) {
            allocatedMemory = malloc(buf_size + 1);
        } else {
            return EXIT_FAILURE;
        }
        if (allocatedMemory) {
        str->data = allocatedMemory;
        str->capacity_m = buf_size ? buf_size : str_len(cstr);
        str->size_m = str_len(cstr);
        str->data = cstr;
        return EXIT_SUCCESS;
        }

    }

    return EXIT_FAILURE;
}

//! Створити стрічку із буфером вказаного розміру. Пам'ять виділяється динамічно.
//! Варто виділяти buf_size+1 для спрощення роботи my_str_get_cstr().
int my_str_create(my_str_t *str, size_t buf_size) {
    if (str) {
        char *allocatedMemory = malloc(buf_size + 1);
        if (allocatedMemory) {
            str->data = allocatedMemory;
            str->capacity_m = buf_size;
            str->size_m = 0;
            str->data[0] = '\0';
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAILURE;
}

//! Повертає розмір стрічки:
size_t my_str_size(const my_str_t *str) {
    return str->size_m;
}

//! Повертає розмір буфера:
void my_str_free(my_str_t *str) {
    free(str->data);
}

size_t my_str_capacity(const my_str_t *str) {
    return str->capacity_m;
};

//! Додає символ в кінець.
//! Повертає 0, якщо успішно, -1, якщо буфер закінчився.
int my_str_pushback(my_str_t* str, char c){
    if((str->size_m + 1) > str->capacity_m) {
        return EXIT_FAILURE;
    } else {
        str->data[str->size_m] = c;
        str->data[str->size_m + 1] = '\0';
        str->size_m++;
        return EXIT_SUCCESS;
    }
}

//! Додати С-стрічку в кінець.
//! Якщо це неможливо, повертає -1, інакше 0.
int my_str_append_cstr(my_str_t* str, char* from) {

    if (str->capacity_m - str->size_m < str_len(from)) return EXIT_FAILURE;

    while (*from++) {
        my_str_pushback(str, *from);
    }

    return EXIT_SUCCESS;
}

void getZarr(char str[], int Z[])
{
    size_t n = str_len(str);
    int L, R, k;

    L = R = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && str[R-L] == str[R])
                R++;
            Z[i] = R - L;
            R--;
        } else {
            k = i - L;
            if (Z[k] < R-i+1) {
                Z[i] = Z[k];
            } else {
                L = i;
                while (R<n && str[R-L] == str[R]) R++;
                Z[i] = R-L;
                R--;
            }
        }
    }
}

//! Очищає стрічку -- робить її порожньою. Складність має бути О(1).
void my_str_clear(my_str_t* str){
    my_str_create(str, str->capacity_m);
}

//! Скопіювати підстрічку, із beg включно, по end не включно ([beg, end)).
//! Якщо end виходить за межі str -- скопіювати скільки вдасться, не вважати
//! це помилкою. Якщо ж в ціловій стрічці замало місця, або beg більший
//! за розмір str -- це помилка. Повернути відповідний код завершення.
int my_str_substr(const my_str_t* str, my_str_t* to, size_t beg, size_t end){
    if(end - beg > to->capacity_m || beg >= str->size_m) {
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

//! Знайти першу підстрічку в стрічці, повернути номер її
//! початку або -1u, якщо не знайдено. from -- місце, з якого починати шукати.
//! Якщо більше за розмір -- вважати, що не знайдено.
size_t my_str_find(const my_str_t* str, const my_str_t* tofind, size_t from){
    if (tofind->size_m > str->size_m) return (size_t)-1u;
    size_t size_of_str = str->size_m;
    char *text = malloc(tofind->size_m + 1 + size_of_str - from);
    my_str_t str_in_use;
    my_str_create(&str_in_use, size_of_str);
    my_str_substr(str, &str_in_use, from, size_of_str);
    str_copy(text, tofind->data);
    str_cat(text, "$");
    str_cat(text, str_in_use.data);
    size_t l = str_len(text);

    int Z[l];
    getZarr(text, Z);

    for (int i = 0; i < l; ++i)
    {
        if (Z[i] == str_len(tofind->data)) return i - str_len(tofind->data) - 1;
    }

    return (size_t)-1u;

}


int main() {

    printf("Hello, World!\n");
    printf("Hello, World!\n");

    char cstr[] = "hello";
    my_str_t this;

//    test cstr to str
    printf("\ntest cstr to str\n");
    my_str_from_cstr(&this, cstr, 30);
    printf("%s\n", this.data);
    printf("%zu\n", this.size_m);
    printf("%zu\n", this.capacity_m);

    char cstr2[] = ", world";
//    test append cstr
    printf("\ntest append cstr\n");
    my_str_append_cstr(&this, cstr2);
    printf("new %s\n", this.data);
    printf("%zu\n", this.size_m);
    printf("%zu", this.capacity_m);

//    test copy
    printf("\ntest copy\n");
    char try_copy[] = "try copy! 123";
    char to_copy[30];
    str_copy(to_copy, try_copy);
    printf("%s", to_copy);

//    test cat
    printf("\ntest cat\n");
    char yes[] = " yes";
    char *after_cat[30];
    *after_cat = str_cat(to_copy, yes);
    printf("%s", *after_cat);

//    test find substring
    printf("\ntest find substring\n");
    my_str_t to_find;
    my_str_from_cstr(&to_find, "or", 30);
    printf("search %s in %s\n", to_find.data, this.data);
    printf("%zu", my_str_find(&this, &to_find, 0));

//    test get substring
    printf("\ntest get substring\n");
    my_str_t substr;
    my_str_create(&substr, 30);
    printf("\nbefore: %s", substr.data);
    my_str_substr(&this, &substr, 6, this.size_m);
    printf("\nafter: %s", substr.data);

    return 0;
}