//
// Created by 0x7cc on 2020/3/8.
//

#if __linux__

#include "pb/pb.h"
#include "pb/internal/pb.h"
#include "pb/term.h"

#include <stdlib.h>
#include <stdio.h>

void pb_update (ppb pb)
{
  vector2 sz;
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

  free (buf);
}

#endif
