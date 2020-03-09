//
// Created by x7cc on 2020/3/9.
//

#ifndef PB_MISC_H
#define PB_MISC_H

#include <stdint.h>

#define __max(a, b) (((a) > (b)) ? (a) : (b))
#define __min(a, b) (((a) < (b)) ? (a) : (b))

void __sleep (uint64_t ms);

#endif //PB_MISC_H
