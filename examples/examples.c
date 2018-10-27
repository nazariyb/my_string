//
// Created by arattel on 27.10.18.
//
#include "my_string.h"
#include <stdio.h>

void main() {

    // Example of type casting
    my_str_t test_string0;

    // Example of my_str_t creation
    my_str_create(&test_string0, 38);

    //Example of pushback function
    my_str_pushback(&test_string0, '1');
    printf("\nPushback");
    printf("\nResult: \"%s\" \n", test_string0.data);
    printf("Length: %ld\n", test_string0.size_m);

    // Example of appending c-string
    printf("\nAppending c-string\n");
    printf("Before: \"%s\"", test_string0.data);
    my_str_append_cstr(&test_string0, "3619");
    printf("\nAfter\"%s\" \n", test_string0.data);
    printf("Length: %ld\n", test_string0.size_m);

    // Example of creation my_str_t from c-string
    printf("\nCreation my_str_t from c-string\n");
    my_str_t test_string1;
    my_str_from_cstr(&test_string1, "Hello world", 38);
    printf("Result: \"%s\"\n", test_string1.data);
    printf("Length: %ld\n", test_string1.size_m);

    // Example of popback function
    printf("\nPopback\n");
    printf("Before: \"%s\"\n", test_string1.data);
    printf("Length before: %ld\n", test_string1.size_m);
    printf("Character popped: \'%c\'\n", my_str_popback(&test_string1));
    printf("After: \"%s\"\n", test_string1.data);
    printf("Length after: %ld\n", test_string1.size_m);

    // Example of copying
    printf("\nCopying\n");
    my_str_t test_string2;
    my_str_copy(&test_string1, &test_string2, 1);
    printf("After: \"%s\"\n", test_string2.data);
    printf("Length after: %ld\n", test_string2.size_m);

    // Example of size
    printf("\nSize\n");
    printf("Size of test string 2: %ld\n", my_str_size(&test_string2));

    // Example of empty
    printf("\nEmpty\n");
    printf("Test string 2 is empty: %d\n", my_str_empty(&test_string2));

    // Example of free
    printf("\nFree\n");
    my_str_free(&test_string2);
    printf("String after: \"%s\"\n", test_string2.data);

    // Exaple of capacity
    printf("\nCapacity\n");
    printf("Test string 2 capacity: %ld\n", my_str_capacity(&test_string2));

    // Example of clear
    my_str_clear(&test_string1);

    //Example of substring
    printf("\nSubstring\n");
    my_str_t test_string3;
    my_str_create(&test_string3, 50);
    my_str_substr(&test_string0, &test_string3, 1, 3);
    printf("Result: \"%s\"\n", test_string3.data);
    printf("Result length: %ld\n", test_string3.size_m);

    //Example of finding substring
    printf("\nSubstring find\n");
    printf("test string 3 is: %s, test string 0 is: %s\n", test_string3.data, test_string0.data);
    printf("Index of test string 3 in test string 0: %ld\n", my_str_find(&test_string0, &test_string3, 0));

    // Example of getting character
    printf("\nGetting character\n");
    printf("Characted on position 3 in test string 0: \'%c\'\n", (char) my_str_getc(&test_string0, 3));

    // Example of putting character
    printf("\nPutting character\n");
    printf("Before: \"%s\"\n", test_string0.data);
    my_str_putc(&test_string0,  2, 'k');
    printf("After putting character \'k\' in position 2: \"%s\"\n", test_string0.data);

    // Example of getting last character
    printf("\nGetting last character\n");
    printf("Last character of string \"%s\": \'%c\'\n", test_string0.data, (char) my_str_getlast(&test_string0));

    // Example of printing
    printf("\nPrinting\n");
    my_str_print(&test_string0);

    // Example of getting c-string from my_str_t
    char *string_example = my_str_getdata(&test_string0);

    // Example of inserting character
    printf("\nInsert character\n");
    printf("Before: \"%s\"\n", test_string0.data);
    my_str_insert_c(&test_string0, 'm', 4);
    printf("After inserting character \'m\' in position 4: \"%s\"\n", test_string0.data);

    // Example of inserting another my_str_t
    printf("\nInsert another my_str_t\n");
    my_str_insert(&test_string0, &test_string3, 3);
    printf("After inserting  test string 3 in position 3: \"%s\"\n", test_string0.data);

    // Example of inserting c-string
    printf("\nInsert c-string\n");
    char *c_string = "Alaska";
    my_str_insert_cstr(&test_string0, c_string, 1);
    printf("After inserting  c-string in position 1: \"%s\"\n", test_string0.data);

    // Example of appending another my_str_t
    printf("\nAppending another my_str_t\n");
    printf("Before: \"%s\"\n", test_string3.data);
    my_str_append(&test_string3, &test_string0);
    printf("After appending \"%s\": %s\n", my_str_getdata(&test_string0), test_string3.data);
    printf("Size after appending: %zu\n", test_string3.size_m);

    // Example of comparison
    printf("\nComparison\n");
    printf("Comparison \"%s\" function with \"ignite\" returned: %d\n", my_str_getdata(&test_string0), my_str_cmp(&test_string0, "ignite"));

    // Example of getting cstr
    const char * cstr = my_str_get_cstr(&test_string3);

    // Example of finding character
    printf("\nFinding character\n");
    printf("Character \'1\' is on position %zu in word \"%s\"\n", my_str_find_c(&test_string3, '1', 1), test_string3.data);
    my_str_t test_string4;
    my_str_create(&test_string4, 38);
}