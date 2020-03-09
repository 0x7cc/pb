//
// Created by x7cc on 2020/3/9.
//

#include "pb/internal/misc.h"

#if WIN32

#include <windows.h>

void __sleep (uint64_t ms)
{
  Sleep (ms);
}

#endif
