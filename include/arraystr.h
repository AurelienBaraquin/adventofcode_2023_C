/*
** EPITECH PROJECT, 2023
** class_implementation_test
** File description:
** arraystr
*/

#ifndef ARRAYSTR_H_
#define ARRAYSTR_H_

#include "std.h"
#include "list.h"
#include "str.h"

typedef struct arraystr_s Arraystr;

typedef void (*__arraystr_destroy_t)(struct arraystr_s *self);
typedef struct arraystr_s * (*__arraystr_push_back_t)(struct arraystr_s *self, String *str);
typedef struct arraystr_s * (*__arraystr_push_front_t)(struct arraystr_s *self, String *str);
typedef String * (*__arraystr_pop_back_t)(struct arraystr_s *self);
typedef String * (*__arraystr_pop_front_t)(struct arraystr_s *self);
typedef struct arraystr_s * (*__arraystr_insert_t)(struct arraystr_s *self, size_t index, String *str);
typedef struct arraystr_s * (*__arraystr_erase_t)(struct arraystr_s *self, size_t index);
typedef struct arraystr_s * (*__arraystr_clear_t)(struct arraystr_s *self);
typedef struct arraystr_s * (*__arraystr_sort_t)(struct arraystr_s *self, bool (*cmp)(void *str1, void *str2));
typedef String * (*__arraystr_at_str_t)(struct arraystr_s *self, size_t index);
typedef char (*__arraystr_at_char_t)(struct arraystr_s *self, size_t index1, size_t index2);
typedef String * (*__arraystr_front_t)(struct arraystr_s *self);
typedef String * (*__arraystr_back_t)(struct arraystr_s *self);
typedef String * (*__arraystr_find_t)(struct arraystr_s *self, String *str);
typedef bool (*__arraystr_empty_t)(struct arraystr_s *self);
typedef size_t (*__arraystr_size_t)(struct arraystr_s *self);
typedef void (*__arraystr_print_t)(struct arraystr_s *self, void (*print)(void *str));

struct arraystr_s {
    List                    *list;
    __arraystr_destroy_t    destroy;
    __arraystr_push_back_t  push_back;
    __arraystr_push_front_t push_front;
    __arraystr_pop_back_t   pop_back;
    __arraystr_pop_front_t  pop_front;
    __arraystr_insert_t     insert;
    __arraystr_erase_t      erase;
    __arraystr_clear_t      clear;
    __arraystr_sort_t       sort;
    __arraystr_at_str_t     at_str;
    __arraystr_at_char_t    at_char;
    __arraystr_front_t      front;
    __arraystr_back_t       back;
    __arraystr_find_t       find;
    __arraystr_empty_t      empty;
    __arraystr_size_t       size;
    __arraystr_print_t      print;
};

Arraystr *Arraystr_create(void);
void Arraystr_handler_private(int mode, Arraystr *arr);

#endif /* !ARRAYSTR_H_ */
