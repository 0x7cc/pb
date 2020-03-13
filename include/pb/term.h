//
// Created by 0x7cc on 2020/3/8.
//

#ifndef PB_TERM_H
#define PB_TERM_H

#include "pb/native.h"
#include "pb/vector.h"

PB_PUBLIC void term_init ();

PB_PUBLIC void term_window_size (vector2* size);

PB_PUBLIC void term_get_cursor_pos (vector2* size);

PB_PUBLIC void term_set_cursor_pos (const vector2* size);

PB_PUBLIC void term_lock_stdin ();

PB_PUBLIC void term_unlock_stdin ();

#endif //PB_TERM_H
