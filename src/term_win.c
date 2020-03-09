//
// Created by 0x7cc on 2020/3/8.
//

#if WIN32

#include "pb/term.h"

#include <stdio.h>
#include <windows.h>

HANDLE PB_STDOUT = 0;

void term_init ()
{
  if (PB_STDOUT == 0)
    PB_STDOUT = GetStdHandle (STD_OUTPUT_HANDLE);
}

void term_window_size (vector2* size)
{
  CONSOLE_SCREEN_BUFFER_INFO ConsoleScreenBufferInfo = {0};
  GetConsoleScreenBufferInfo (PB_STDOUT, &ConsoleScreenBufferInfo);

  size->x = ConsoleScreenBufferInfo.srWindow.Right - ConsoleScreenBufferInfo.srWindow.Left + 1;
  size->y = ConsoleScreenBufferInfo.srWindow.Bottom - ConsoleScreenBufferInfo.srWindow.Top + 1;
  SetConsoleCursorPosition (PB_STDOUT, ConsoleScreenBufferInfo.dwCursorPosition);
}

void term_get_cursor_pos (vector2* pos)
{
  CONSOLE_SCREEN_BUFFER_INFO ConsoleScreenBufferInfo = {0};
  GetConsoleScreenBufferInfo (PB_STDOUT, &ConsoleScreenBufferInfo);

  pos->x = ConsoleScreenBufferInfo.dwCursorPosition.X;
  pos->y = ConsoleScreenBufferInfo.dwCursorPosition.Y;
}

void term_set_cursor_pos (const vector2* pos)
{
  COORD dwCursorPosition = {pos->x, pos->y};
  SetConsoleCursorPosition (PB_STDOUT, dwCursorPosition);
}

void term_lock_stdin ()
{
  DWORD               ConsoleMode;
  CONSOLE_CURSOR_INFO ConsoleCursorInfo;

  GetConsoleMode (PB_STDOUT, &ConsoleMode);

  ConsoleMode &= ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT | ENABLE_WINDOW_INPUT);

  SetConsoleMode (PB_STDOUT, ConsoleMode);

  GetConsoleCursorInfo (PB_STDOUT, &ConsoleCursorInfo);
  ConsoleCursorInfo.bVisible = FALSE;
  SetConsoleCursorInfo (PB_STDOUT, &ConsoleCursorInfo);
}

void term_unlock_stdin ()
{
  DWORD               ConsoleMode;
  CONSOLE_CURSOR_INFO ConsoleCursorInfo;

  GetConsoleMode (PB_STDOUT, &ConsoleMode);

  ConsoleMode |= (ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT | ENABLE_WINDOW_INPUT);

  SetConsoleMode (PB_STDOUT, ConsoleMode);

  GetConsoleCursorInfo (PB_STDOUT, &ConsoleCursorInfo);
  ConsoleCursorInfo.bVisible = TRUE;
  SetConsoleCursorInfo (PB_STDOUT, &ConsoleCursorInfo);
}

#endif
