
#ifndef PB_INTERNAL_PB_H
#define PB_INTERNAL_PB_H

#include "linked_list.h"
#include "xstring.h"

#include <stdint.h>

struct pb_task_t
{
  LINKED_LIST_NODE _;

  uint64_t total;
  uint64_t value;
  uint8_t  show_percent;
  uint8_t  show_progress;
  uint8_t  show_prefix;
  uint8_t  show_suffix;
  xstring* prefix;
  xstring* suffix;
};

struct pb_t
{
  struct pb_task_t tasks;
  uint8_t          n_last_rows;
  uint8_t          n_rows;
  uint8_t          first;
};

#endif
