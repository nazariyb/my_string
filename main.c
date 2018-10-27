#include "my_string.h"
#include <stdio.h>



void main() {
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

    printf("\nTest pushback: \n");
    printf("\nBefore: %s\n", this.data);
    my_str_pushback(&this, ',');
    printf("\nAfter: %s\n", this.data);

    printf("\nTest pohback: \n");
    printf("\nBefore: %s\n", this.data);
    my_str_popback(&this);
    printf("\nAfter: %s\n", this.data);

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
    printf("\nafter: %s\n", substr.data);


    printf("\nTest find:\n");
    my_str_t test_str;
    my_str_create(&test_str, 20);
    my_str_pushback(&test_str, '2');
    my_str_pushback(&test_str, '1');
    my_str_pushback(&test_str, '0');
    my_str_pushback(&test_str, '1');
    printf("Our string: %s\n", test_str.data);
    printf("Index of 1, beginning with 0: %zu\n", my_str_find_c(&test_str, '1', 0));
    printf("Index of 1, beginning with 2: %zu\n", my_str_find_c(&test_str, '1', 2));
    printf("Index of 8, beginning with 0: %zu\n", my_str_find_c(&test_str, '8', 0));
    printf("\nTest find if:\n");
    printf("Our string: %s\n", test_str.data);
    printf("Index of first symbol that is either 1 or 8: %zu", my_str_find_if(&test_str, &test_function_for_chars));
//    test pop
    printf("\ntest pop\n");
    my_str_t new_this;
    my_str_from_cstr(&new_this, "12345", 20);
    printf("Before: %s\n", new_this.data);
    printf("Char deleted: %c\n",(char)my_str_popback(&new_this));
    printf("After: %s\n", new_this.data);
    return 0;
}

