/*
** EPITECH PROJECT, 2023
** class_implementation_test
** File description:
** list
*/

#ifndef LIST_H_
#define LIST_H_

#include "std.h"

typedef struct __list__s {
    void                *data;
    struct __list__s   *next;
} __list__t;

typedef struct list_s List;

typedef void (*__list_destroy_t)(struct list_s *self, void (*data_destroy)(void *data));
typedef void (*__list_push_front_t)(struct list_s *self, void *data);
typedef void (*__list_push_back_t)(struct list_s *self, void *data);
typedef void (* __list_insert_t)(struct list_s *self, void *data, size_t index);
typedef void (* __list_replace_t)(struct list_s *self, void *data, size_t index, void (*data_destroy)(void *data));
typedef void * (*__list_pop_front_t)(struct list_s *self);
typedef void * (*__list_pop_back_t)(struct list_s *self);
typedef void * (*__list_front_t)(struct list_s *self);
typedef void * (*__list_back_t)(struct list_s *self);
typedef void * (*__list_at_t)(struct list_s *self, size_t index);
typedef void * (*__list_find_t)(struct list_s *self, void *data, bool (*cmp)(void *data1, void *data2));
typedef void (*__list_erase_t)(struct list_s *self, size_t index, void (*data_destroy)(void *data));
typedef void (*__list_clear_t)(struct list_s *self, void (*data_destroy)(void *data));
typedef void (*__list_sort_t)(struct list_s *self, bool (*cmp)(void *data1, void *data2));
typedef bool (*__list_empty_t)(struct list_s *self);
typedef size_t (*__list_size_t)(struct list_s *self);
typedef void (*__list_print_t)(struct list_s *self, void (*print)(void *data));

struct list_s {
    __list__t              *list;
    __list_destroy_t       destroy;
    __list_push_front_t    push_front;
    __list_push_back_t     push_back;
    __list_insert_t        insert;
    __list_replace_t       replace;
    __list_pop_front_t     pop_front;
    __list_pop_back_t      pop_back;
    __list_front_t         front;
    __list_back_t          back;
    __list_at_t            at;
    __list_find_t          find;
    __list_erase_t         erase;
    __list_clear_t         clear;
    __list_sort_t          sort;
    __list_empty_t         empty;
    __list_size_t          size;
    __list_print_t         print;
};

List *List_create(void);

#endif /* !LIST_H_ */
