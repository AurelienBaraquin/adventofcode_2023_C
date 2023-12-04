/*
** EPITECH PROJECT, 2023
** class_implementation_test
** File description:
** vector2d
*/

#ifndef VECTOR2D_H_
#define VECTOR2D_H_

#include "std.h"
#include "queue.h"

typedef struct vector2d_s Vector2d;

typedef void (*__vector2d_destroy_t)(struct vector2d_s *self);
typedef void (*__vector2d_set_x_t)(struct vector2d_s *self, float x);
typedef void (*__vector2d_set_y_t)(struct vector2d_s *self, float y);
typedef void (*__vector2d_set_t)(struct vector2d_s *self, float x, float y);
typedef float (*__vector2d_get_x_t)(struct vector2d_s *self);
typedef float (*__vector2d_get_y_t)(struct vector2d_s *self);
typedef void (*__vector2d_print_t)(struct vector2d_s *self);

typedef Vector2d *(*__vector2d_add_t)(struct vector2d_s *self, struct vector2d_s *other);
typedef Vector2d *(*__vector2d_sub_t)(struct vector2d_s *self, struct vector2d_s *other);
typedef Vector2d *(*__vector2d_mul_t)(struct vector2d_s *self, struct vector2d_s *other);
typedef Vector2d *(*__vector2d_div_t)(struct vector2d_s *self, struct vector2d_s *other);

typedef Vector2d *(*__vector2d_add_scalar_t)(struct vector2d_s *self, float scalar);
typedef Vector2d *(*__vector2d_sub_scalar_t)(struct vector2d_s *self, float scalar);
typedef Vector2d *(*__vector2d_mul_scalar_t)(struct vector2d_s *self, float scalar);
typedef Vector2d *(*__vector2d_div_scalar_t)(struct vector2d_s *self, float scalar);

struct vector2d_s {
    float                   x;
    float                   y;
    __vector2d_destroy_t    destroy;
    __vector2d_set_x_t      set_x;
    __vector2d_set_y_t      set_y;
    __vector2d_set_t        set;
    __vector2d_get_x_t      get_x;
    __vector2d_get_y_t      get_y;
    __vector2d_print_t      print;
    __vector2d_add_t        add;
    __vector2d_sub_t        sub;
    __vector2d_mul_t        mul;
    __vector2d_div_t        div;
    __vector2d_add_scalar_t add_scalar;
    __vector2d_sub_scalar_t sub_scalar;
    __vector2d_mul_scalar_t mul_scalar;
    __vector2d_div_scalar_t div_scalar;
};

Vector2d *Vector2d_create(float x, float y);
void Vector2d_handler_private(int mode, Vector2d *str);

#endif /* !VECTOR2D_H_ */
