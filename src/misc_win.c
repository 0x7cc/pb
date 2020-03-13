//
// Created by x7cc on 2020/3/9.
//

#if WIN32

#include "internal/misc.h"

#include <windows.h>

void __sleep (uint64_t ms)
{
  Sleep (ms);
}

#endif
