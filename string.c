//
// Created by arattel on 20.10.18.
//
struct my_str_t
{
    size_t capacity_m; // Розмір блока
    size_t size_m;     // Фактичний розмір стрічки
    char*  data;       // Вказівник на блок пам'яті
};

