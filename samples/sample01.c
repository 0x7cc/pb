//
// Created by 0x7cc on 2020/3/8.
//

#include <pb/pb.h>
#include <pb/term.h>
#include <internal/misc.h>

#include <stdio.h>

int main (int argc, char* argv[])
{
  vector2  size;
  uint64_t total = 333;
  ppb      pb    = pb_new ();
  ppb_task task1 = pb_task_new ();
  ppb_task task2 = pb_task_new ();

  pb_task_set_total (task1, total);

  pb_task_set_total (task2, total);

  pb_task_set_prefix (task1, "this is task1", 13);
  pb_task_set_prefix (task2, "this is task2", 13);

  pb_add (pb, task1);
  pb_add (pb, task2);

  term_window_size (&size);
  printf ("Screen width: %d Screen height: %d\n", size.x, size.y);

  term_lock_stdin ();

  for (int i = 0; i <= total; ++i)
  {
    __sleep (100);
    pb_task_set_value (task1, i);
    pb_task_set_value (task2, i * 2);
    pb_update (pb);

    if (i < 3)
    {
      ppb_task t = pb_task_new ();
      pb_add (pb, t);
      pb_task_set_value (t, 100 - i);
      pb_task_set_prefix (t, "This is a dynamically added task", 32);
    }
  }

  term_unlock_stdin ();

  pb_task_delete (task2);
  pb_task_delete (task1);
  pb_delete (pb);

  return 0;
}
