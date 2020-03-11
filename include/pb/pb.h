//
// Created by 0x7cc on 2020/3/8.
//

#ifndef PB_PB_H
#define PB_PB_H

#include "pb/native.h"

#include <stdint.h>

struct pb_t;
typedef struct pb_t* ppb;

struct pb_task_t;
typedef struct pb_task_t* ppb_task;

PB_PUBLIC ppb pb_new ();

PB_PUBLIC void pb_delete (ppb pb);

PB_PUBLIC void pb_add (ppb pb, ppb_task task);

PB_PUBLIC void pb_update (ppb pb);

PB_PUBLIC ppb_task pb_task_new ();

PB_PUBLIC void pb_task_delete (ppb_task task);

PB_PUBLIC void pb_task_set_total (ppb_task task, uint64_t total);

PB_PUBLIC void pb_task_set_value (ppb_task task, uint64_t value);

PB_PUBLIC void pb_task_set_prefix (ppb_task task, const char* prefix, uint32_t len);

PB_PUBLIC void pb_task_set_suffix (ppb_task task, const char* suffix, uint32_t len);

#endif // PB_PB_H
