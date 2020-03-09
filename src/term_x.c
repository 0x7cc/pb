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

void term_size (TERM_SIZE* size)
{
  struct winsize sz = {0};
  if (ioctl (tty, TIOCGWINSZ, &sz) != 0)
  {
    perror ("ioctl");
  }
  size->x = sz.ws_col;
  size->y = sz.ws_row;
}

void term_lock_stdin ()
{
  //  struct termios io = {0};
  //  ioctl (tty, TCGETS, &io);
  //  struct termios io2 = io;
  //  io2.c_lflag &= ~ECHO;
  //  io2.c_lflag |= ICANON | ISIG;
  //  io2.c_iflag |= ICRNL;
  //  ioctl (tty, TCSETS, &io2);
  //  ioctl(0, TCSETS, 0);
}

void term_unlock_stdin ()
{
}

#endif
