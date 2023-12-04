/*
** EPITECH PROJECT, 2023
** CLASS_LIB
** File description:
** ifstream
*/

#ifndef IFSTREAM_H_
#define IFSTREAM_H_

#include "std.h"
#include "queue.h"

typedef struct ifstream_s ifStream;

typedef void (*__ifstream_destroy_t)(struct ifstream_s *self);
typedef char *(*__ifstream_getchar_t)(struct ifstream_s *self);
typedef char *(*__ifstream_getline_t)(struct ifstream_s *self);
typedef char *(*__ifstream_getall_t)(struct ifstream_s *self);
typedef char *(*__ifstream_getto_t)(struct ifstream_s *self, char *to);
typedef int (*__ifstream_size_t)(struct ifstream_s *self);
typedef void (*__ifstream_close_t)(struct ifstream_s *self);

struct ifstream_s {
    char                *filename;
    bool                 is_open;
    FILE                *stream;
    char                *buffer;
    __ifstream_destroy_t destroy;
    __ifstream_getchar_t getchar;
    __ifstream_getline_t getline;
    __ifstream_getall_t  getall;
    __ifstream_getto_t   getto;
    __ifstream_size_t    size;
    __ifstream_close_t   close;
};

ifStream *ifStream_create(char *str);
void ifStream_handler_private(int mode, ifStream *str);

#endif /* !IFSTREAM_H_ */
