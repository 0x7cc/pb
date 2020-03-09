//
// Created by x7cc on 2020/3/9.
//

#if __linux__ || __APPLE__

#include "pb/internal/misc.h"

#include <unistd.h>

void __sleep (uint64_t ms)
{
  useconds_t useconds = ms * 1000;
  usleep (useconds);
}

#endif
