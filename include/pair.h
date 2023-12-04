/*
** EPITECH PROJECT, 2023
** class_implementation_test
** File description:
** pair
*/

#ifndef PAIR_H_
#define PAIR_H_

#include "std.h"

typedef struct pair_s Pair;

typedef void (*__pair_destroy_t)(struct pair_s *self, void (*data_destroy)(void *first, void *second));
typedef void (*__pair_set_first_t)(struct pair_s *self, void *data);
typedef void (*__pair_set_second_t)(struct pair_s *self, void *data);
typedef void * (*__pair_get_first_t)(struct pair_s *self);
typedef void * (*__pair_get_second_t)(struct pair_s *self);
typedef void (*__pair_print_t)(struct pair_s *self, void (*print)(void *first, void *second));
typedef bool (*__pair_equal_t)(struct pair_s *self, struct pair_s *other);
typedef bool (*__pair_less_t)(struct pair_s *self, struct pair_s *other);
typedef bool (*__pair_greater_t)(struct pair_s *self, struct pair_s *other);

struct pair_s {
    void                *first;
    void                *second;
    __pair_destroy_t    destroy;
    __pair_set_first_t  set_first;
    __pair_set_second_t set_second;
    __pair_get_first_t  get_first;
    __pair_get_second_t get_second;
    __pair_print_t      print;
    __pair_equal_t      equal;
    __pair_less_t       less;
    __pair_greater_t    greater;
};

Pair *Pair_create(void *first, void *second);

#endif /* !PAIR_H_ */
