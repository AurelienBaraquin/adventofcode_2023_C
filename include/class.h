/*
** EPITECH PROJECT, 2023
** class_implementation_test
** File description:
** new
*/

#ifndef CLASS_H_
#define CLASS_H_

#include "std.h"
#include "queue.h"
#include "stack.h"
#include "list.h"
#include "map.h"
#include "vector2d.h" // auto free enable
#include "pair.h"
#include "str.h" // auto free enable
#include "arraystr.h" // auto free enable
#include "ifstream.h" // auto free enable

#define NEW(type, ...) \
    (type##_create(__VA_ARGS__))

    #ifndef String
        #define STRING_HANDLER String_handler_private(1, NULL)
    #else
        #define STRING_HANDLER (void *)0
    #endif

    #ifndef Vector2d
        #define VECTOR2D_HANDLER Vector2d_handler_private(1, NULL)
    #else
        #define VECTOR2D_HANDLER (void *)0
    #endif

    #ifndef Arraystr
        #define ARRAYSTR_HANDLER Arraystr_handler_private(1, NULL)
    #else
        #define ARRAYSTR_HANDLER (void *)0
    #endif

    #ifndef ifStream
        #define IFSTREAM_HANDLER Ifstream_handler_private(1, NULL)
    #else
        #define IFSTREAM_HANDLER (void *)0
    #endif

//* SHORTCUTS

    #ifndef String
        #define LIST_STRING_AT(list, char, index1, index2) ((String *)list->at(list, index1))->set_at(((String *)list->at(list, index1)), index2, char)
    #endif

    void exit_handler(void);
    #define ENABLE_AUTO_FREE atexit(&exit_handler)

#endif /* !CLASS_H_ */
