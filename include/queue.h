/*
** EPITECH PROJECT, 2023
** class_implementation_test
** File description:
** queue
*/

#ifndef QUEUE_H_
#define QUEUE_H_

#include "std.h"

typedef struct __queue__s {
    void                *data;
    struct __queue__s   *next;
} __queue__t;

typedef struct queue_s Queue;

typedef void (*__queue_destroy_t)(struct queue_s *self, void (*data_destroy)(void *data));
typedef void (*__queue_push_t)(struct queue_s *self, void *data);
typedef void * (*__queue_pop_t)(struct queue_s *self);
typedef void * (*__queue_front_t)(struct queue_s *self);
typedef void * (*__queue_back_t)(struct queue_s *self);
typedef bool (*__queue_empty_t)(struct queue_s *self);
typedef size_t (*__queue_size_t)(struct queue_s *self);

struct queue_s {
    __queue__t              *queue;
    __queue_destroy_t       destroy;
    __queue_push_t          push;
    __queue_pop_t           pop;
    __queue_front_t         front;
    __queue_back_t          back;
    __queue_empty_t         empty;
    __queue_size_t          size;
};

Queue *Queue_create(void);

#endif /* !QUEUE_H_ */
