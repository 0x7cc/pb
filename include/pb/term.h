//
// Created by 0x7cc on 2020/3/8.
//

#ifndef PB_TERM_H
#define PB_TERM_H

#include <stdint.h>

typedef struct
{
  uint16_t x;
  uint16_t y;
} vector2;

typedef struct
{
  uint16_t x;
  uint16_t y;
  uint16_t z;
} vector3;

typedef struct
{
  uint16_t x;
  uint16_t y;
  uint16_t z;
  uint16_t w;
} vector4;

void term_init ();

void term_size (vector2* size);

void term_get_cursor_pos (vector2* size);

void term_set_cursor_pos (const vector2* size);

void term_lock_stdin ();

void term_unlock_stdin ();

#endif //PB_TERM_H
