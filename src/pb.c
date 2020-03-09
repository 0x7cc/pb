//
// Created by 0x7cc on 2020/3/8.
//

#include "pb/pb.h"
#include "pb/internal/pb.h"
#include "pb/internal/misc.h"
#include "pb/internal/xstring.h"
#include "pb/term.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

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
  vector2 sz, pos;
  term_window_size (&sz);
  term_get_cursor_pos (&pos);

  xstring* lines = xstring_new (pb->n_rows * sz.x + pb->n_rows);

  if (pb->first == 0)
  {
    pos.y -= pb->n_last_rows;
    term_set_cursor_pos (&pos);
  }

  int pbWidth = __min (20, sz.x * 0.3);
  PB_LINKED_LIST_FOREACH (&(pb->tasks))
  {
    double value   = ((ppb_task)node)->value;
    double total   = ((ppb_task)node)->total;
    double percent = value / total;
    int    full    = __min (pbWidth, pbWidth * percent);

    xstring* line     = xstring_new (sz.x);
    xstring* progress = xstring_new (sz.x);
    xstring* suffix   = xstring_new (sz.x);

    xstring_appendC (progress, '[');
    xstring_appendN (progress, '#', full);
    xstring_appendN (progress, ' ', pbWidth - full);
    xstring_appendC (progress, ']');

    if (((ppb_task)node)->show_percent)
      xstring_appendF (progress, "%7.2lf%%", percent * 100);

    if (((ppb_task)node)->show_suffix)
      xstring_appendS (suffix, ((ppb_task)node)->suffix->cstr, ((ppb_task)node)->suffix->len);

    xstring* prefix = xstring_new (line->max - progress->len - suffix->len);
    if (((ppb_task)node)->show_prefix)
      xstring_appendS (prefix, ((ppb_task)node)->prefix->cstr, ((ppb_task)node)->prefix->len);

    xstring_appendS (line, prefix->cstr, prefix->len);

    int placeholder = line->max - prefix->len - progress->len - suffix->len;
    assert (placeholder >= 0);

    xstring_appendN (line, ' ', placeholder);
    xstring_appendS (line, progress->cstr, progress->len);
    xstring_appendS (line, suffix->cstr, suffix->len);

    xstring_appendS (lines, line->cstr, line->len);
    xstring_appendC (lines, '\n');

    xstring_delete (prefix);
    xstring_delete (suffix);
    xstring_delete (progress);
    xstring_delete (line);
  }

  pb->first       = 0;
  pb->n_last_rows = pb->n_rows;

  fwrite (lines->cstr, lines->len, 1, stdout);
  fflush (stdout);

  xstring_delete (lines);
}

ppb_task pb_task_new ()
{
  ppb_task task       = (ppb_task)calloc (1, sizeof (struct pb_task_t));
  task->total         = 100;
  task->show_percent  = 1;
  task->show_progress = 1;
  return task;
}

void pb_task_delete (ppb_task task)
{
  if (task->prefix)
    xstring_delete (task->prefix);

  if (task->suffix)
    xstring_delete (task->suffix);

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

void pb_task_set_prefix (ppb_task task, const char* prefix, uint32_t len)
{
  if (task->prefix)
    xstring_delete (task->prefix);

  task->prefix = xstring_new (len + 1);
  xstring_appendS (task->prefix, prefix, len);
  task->show_prefix = 1;
}

void pb_task_set_suffix (ppb_task task, const char* suffix, uint32_t len)
{
  if (task->suffix)
    xstring_delete (task->suffix);

  task->suffix = xstring_new (len + 1);
  xstring_appendS (task->suffix, suffix, len);
  task->show_suffix = 1;
}
