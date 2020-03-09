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
} TERM_SIZE;

void term_init ();

void term_size (TERM_SIZE* size);

void term_lock_stdin ();

void term_unlock_stdin ();

#endif //PB_TERM_H
