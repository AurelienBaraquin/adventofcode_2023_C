/*
** EPITECH PROJECT, 2023
** class_implementation_test
** File description:
** string
*/

#ifndef STR_H_
#define STR_H_

#include "std.h"
#include "queue.h"

typedef struct string_s String;

typedef void (*__string_destroy_t)(struct string_s *self);
typedef struct string_s* (*__string_assign_c_t)(struct string_s *self, const char *str);
typedef struct string_s* (*__string_assign_s_t)(struct string_s *self, const struct string_s *str);
typedef struct string_s* (*__string_append_c_t)(struct string_s *self, const char *str); // append a char * to a string : "Hello" + " World" = "Hello World"
typedef struct string_s* (*__string_append_s_t)(struct string_s *self, const struct string_s *str);
typedef struct string_s* (*__string_insert_c_t)(struct string_s *self, size_t pos, const char *str);
typedef struct string_s* (*__string_insert_s_t)(struct string_s *self, size_t pos, const struct string_s *str);
typedef struct string_s* (*__string_replace_c_t)(struct string_s *self, const char *str, const char *replace);
typedef struct string_s* (*__string_replace_s_t)(struct string_s *self, const struct string_s *str, const struct string_s *replace);
typedef struct string_s* (*__string_getline_t)(struct string_s *self, FILE *stream);
typedef int (*__string_to_int_t)(struct string_s *self);
typedef struct string_s **(*__string_split_c_t)(struct string_s *self, const char *str);
typedef struct string_s **(*__string_split_s_t)(struct string_s *self, const struct string_s *str);
typedef struct string_s * (*__string_sub_c_t)(struct string_s *self, size_t start, size_t end);
typedef struct string_s * (*__string_sub_s_t)(struct string_s *self, size_t start, size_t end);
typedef struct string_s* (*__string_clear_t)(struct string_s *self);
typedef bool (*__string_contains_c_t)(struct string_s *self, const char *str);
typedef bool (*__string_contains_s_t)(struct string_s *self, const struct string_s *str);
typedef int (*__string_find_c_t)(struct string_s *self, const char *str);
typedef int (*__string_find_s_t)(struct string_s *self, const struct string_s *str);
typedef struct string_s* (*__string_reverse_t)(struct string_s *self);
typedef char (*__string_at_t)(struct string_s *self, size_t pos);
typedef void (*__string_set_at_t)(struct string_s *self, size_t pos, char c);
typedef int (*__string_compare_c_t)(struct string_s *self, const char *str);
typedef int (*__string_compare_s_t)(struct string_s *self, const struct string_s *str);
typedef bool (*__string_empty_t)(struct string_s *self);
typedef size_t (*__string_size_t)(struct string_s *self);
typedef void (*__string_print_t)(struct string_s *self);

struct string_s {
    char                *str;
    __string_destroy_t  destroy;
    __string_assign_c_t assign_c;
    __string_assign_s_t assign_s;
    __string_append_c_t append_c;
    __string_append_s_t append_s;
    __string_insert_c_t insert_c;
    __string_insert_s_t insert_s;
    __string_replace_c_t replace_c;
    __string_replace_s_t replace_s;
    __string_getline_t getline;
    __string_to_int_t to_int;
    __string_split_c_t split_c;
    __string_split_s_t split_s;
    __string_sub_c_t sub_c;
    __string_sub_s_t sub_s;
    __string_clear_t clear;
    __string_contains_c_t contains_c;
    __string_contains_s_t contains_s;
    __string_find_c_t find_c;
    __string_find_s_t find_s;
    __string_reverse_t reverse;
    __string_at_t at;
    __string_set_at_t set_at;
    __string_compare_c_t compare_c;
    __string_compare_s_t compare_s;
    __string_empty_t empty;
    __string_size_t size;
    __string_print_t print;
};

String *String_create(char *str);
void String_handler_private(int mode, String *str);

#endif /* !STR_H_ */
