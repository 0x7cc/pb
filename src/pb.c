//
// Created by 0x7cc on 2020/3/8.
//

#include "pb/pb.h"
#include "pb/term.h"
#include "pb/linked_list.h"

#include <stdlib.h>
#include <stdio.h>

struct pb_task_t
{
  LINKED_LIST_NODE _;

  uint64_t total;
  uint64_t value;
};

struct pb_t
{
  struct pb_task_t tasks;
  uint8_t          n_last_rows;
  uint8_t          n_rows;
  uint8_t          first;
};

ppb pb_new ()
{
  ppb pb    = (ppb)calloc (1, sizeof (struct pb_t));
  pb->first = 1;

  term_init ();

  return pb;
}

void pb_delete (ppb pb)
{
  free (pb);
}

void pb_add (ppb pb, ppb_task task)
{
  PB_LINKED_LIST_APPEND (&(pb->tasks), task);
  ++pb->n_rows;
}

void pb_update (ppb pb)
{
  TERM_SIZE sz;
  term_size (&sz);

  char* buf    = (char*)calloc (1, pb->n_rows * sz.x + sz.x);
  int   offset = 0;

  if (pb->first == 0)
  {
    offset += sprintf (buf + offset, "\033[%dA", pb->n_last_rows);
  }

  PB_LINKED_LIST_FOREACH (&(pb->tasks))
  {
    offset += sprintf (buf + offset, "%lu/%lu\n", ((ppb_task)node)->value, ((ppb_task)node)->total);
  }

  pb->first       = 0;
  pb->n_last_rows = pb->n_rows;

  printf (buf);
  //  fwrite (buf, offset, 1, stdout);
  //  fflush (stdout);
}

ppb_task pb_task_new ()
{
  ppb_task task = (ppb_task)calloc (1, sizeof (struct pb_task_t));
  return task;
}

void pb_task_delete (ppb_task task)
{
  free (task);
}

void pb_task_set_total (ppb_task task, uint64_t total)
{
  task->total = total;
}

void pb_task_set_value (ppb_task task, uint64_t value)
{
  task->value = value;
}
