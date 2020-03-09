//
// Created by 0x7cc on 2020/3/8.
//

#ifndef PB_PB_H
#define PB_PB_H

#include <stdint.h>

extern struct pb_t;
typedef struct pb_t* ppb;

extern struct pb_task_t;
typedef struct pb_task_t* ppb_task;

ppb pb_new ();

void pb_delete (ppb pb);

void pb_add (ppb pb, ppb_task task);

void pb_update (ppb pb);

ppb_task pb_task_new ();

void pb_task_delete (ppb_task task);

void pb_task_set_total (ppb_task task, uint64_t total);

void pb_task_set_value (ppb_task task, uint64_t value);

#endif // PB_PB_H
