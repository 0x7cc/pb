//
// Created by 0x7cc on 2020/3/8.
//

#ifndef PB_TERM_H
#define PB_TERM_H

#include "pb/native.h"

#include <stdint.h>

typedef struct
{
  int16_t x;
  int16_t y;
} vector2;

typedef struct
{
  int16_t x;
  int16_t y;
  int16_t z;
} vector3;

typedef struct
{
  int16_t x;
  int16_t y;
  int16_t z;
  int16_t w;
} vector4;

PB_PUBLIC void term_init ();

PB_PUBLIC void term_window_size (vector2* size);

PB_PUBLIC void term_get_cursor_pos (vector2* size);

PB_PUBLIC void term_set_cursor_pos (const vector2* size);

PB_PUBLIC void term_lock_stdin ();

PB_PUBLIC void term_unlock_stdin ();

#endif //PB_TERM_H
