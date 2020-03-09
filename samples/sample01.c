//
// Created by 0x7cc on 2020/3/8.
//

#include <pb/pb.h>
#include <pb/term.h>

#include <stdio.h>

int main (int argc, char* argv[])
{
  vector2  size;
  uint64_t total = 10000;
  ppb      pb    = pb_new ();
  ppb_task task1 = pb_task_new ();
  ppb_task task2 = pb_task_new ();

  pb_task_set_total (task1, total);

  pb_task_set_total (task2, 20000);

  pb_add (pb, task1);
  pb_add (pb, task2);

  term_size (&size);
  printf ("Screen width: %d Screen height: %d\n", size.x, size.y);

  term_lock_stdin ();

  for (int i = 0; i <= total; ++i)
  {
    pb_task_set_value (task1, i);
    pb_task_set_value (task2, i * 2);
    pb_update (pb);
  }

  term_unlock_stdin ();

  pb_task_delete (task1);
  pb_delete (pb);

  return 0;
}
