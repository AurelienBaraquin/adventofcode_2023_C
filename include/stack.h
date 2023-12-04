/*
** EPITECH PROJECT, 2023
** class_implementation_test
** File description:
** stack
*/

#ifndef STACK_H_
#define STACK_H_

#include "std.h"

typedef struct __stack__s {
    void                *data;
    struct __stack__s   *next;
} __stack__t;

typedef struct stack_s Stack;

typedef void (*__stack_destroy_t)(struct stack_s *self, void (*data_destroy)(void *data));
typedef void (*__stack_push_t)(struct stack_s *self, void *data);
typedef void * (*__stack_pop_t)(struct stack_s *self);
typedef void * (*__stack_front_t)(struct stack_s *self);
typedef bool (*__stack_empty_t)(struct stack_s *self);
typedef size_t (*__stack_size_t)(struct stack_s *self);

struct stack_s {
    __stack__t              *stack;
    __stack_destroy_t       destroy;
    __stack_push_t          push;
    __stack_pop_t           pop;
    __stack_front_t         front;
    __stack_empty_t         empty;
    __stack_size_t          size;
};

Stack *Stack_create(void);

#endif /* !STACK_H_ */
