//
// Created by 0x7cc on 2020/3/8.
//

#if WIN32

#include "pb/pb.h"
#include "pb/internal/pb.h"
#include "pb/term.h"

#include <stdlib.h>
#include <stdio.h>

void pb_update (ppb pb)
{
  vector2 sz, pos;
  term_size (&sz);
  term_get_cursor_pos (&pos);

  char* buf    = (char*)calloc (1, pb->n_rows * sz.x + sz.x);
  int   offset = 0;

  if (pb->first == 0)
  {
    pos.y -= pb->n_last_rows;
    term_set_cursor_pos (&pos);
  }

  PB_LINKED_LIST_FOREACH (&(pb->tasks))
  {
    offset += sprintf (buf + offset, "%lu/%lu\n", ((ppb_task)node)->value, ((ppb_task)node)->total);
  }

  pb->first       = 0;
  pb->n_last_rows = pb->n_rows;

  printf (buf);

  free (buf);
  //  fwrite (buf, offset, 1, stdout);
  //  fflush (stdout);
}

#endif
