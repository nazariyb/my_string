#include <stdio.h>
#include <stdlib.h>

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

int main() {
    printf("Hello, World!\n");
    printf("Hello, World!\n");

    return 0;
}