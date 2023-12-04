/*
** EPITECH PROJECT, 2023
** class_implementation_test
** File description:
** map
*/

#ifndef MAP_H_
#define MAP_H_

#include "std.h"

typedef struct __map__s {
    void                *key;
    void                *value;
    struct __map__s     *next;
} __map__t;

typedef struct map_s Map;

typedef void (*__map_destroy_t)(struct map_s *self, void (*destroy)(void *key, void *value));
typedef void (*__map_insert_t)(struct map_s *self, void *key, void *value);
typedef void (*__map_erase_t)(struct map_s *self, void *key, void (*destroy)(void *key, void *value));
typedef void * (*__map_get_t)(struct map_s *self, void *key);
typedef bool (*__map_empty_t)(struct map_s *self);
typedef size_t (*__map_size_t)(struct map_s *self);
typedef void (*__map_print_t)(struct map_s *self, void (*print)(void *key, void *value));

struct map_s {
    __map__t            *map;
    __map_destroy_t     destroy;
    __map_insert_t      insert;
    __map_erase_t       erase;
    __map_get_t        get;
    __map_empty_t       empty;
    __map_size_t        size;
    __map_print_t       print;
};

Map *Map_create(void);

#endif /* !MAP_H_ */
