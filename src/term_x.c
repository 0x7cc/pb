//
// Created by 0x7cc on 2020/3/8.
//

#if __linux__

#include "pb/term.h"

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

static int tty = 0;

void term_init ()
{
  if (tty == 0)
    tty = open ("/dev/tty", O_RDONLY);
}

void term_size (vector2* size)
{
  struct winsize sz = {0};
  if (ioctl (tty, TIOCGWINSZ, &sz) != 0)
  {
    perror ("ioctl");
  }
  size->x = sz.ws_col;
  size->y = sz.ws_row;
}

void term_get_cursor_pos (vector2* size)
{
}

void term_set_cursor_pos (const vector2* size)
{
}

void term_lock_stdin ()
{
  struct termios io = {0};
  tcgetattr (STDIN_FILENO, &io);
  io.c_lflag &= ~ECHO;
  tcsetattr (STDIN_FILENO, TCSANOW, &io);
}

void term_unlock_stdin ()
{
  struct termios io = {0};
  tcgetattr (STDIN_FILENO, &io);
  io.c_lflag |= ECHO;
  tcsetattr (STDIN_FILENO, TCSANOW, &io);
}

#endif
