//
// Created by x7cc on 2020/3/9.
//

#ifndef PB_XSTRING_H
#define PB_XSTRING_H

#include <stdint.h>

typedef struct
{
  char*    cstr;
  uint32_t max;
  uint32_t len;
} xstring;

xstring* xstring_new (uint32_t len);

void xstring_delete (xstring* xstr);

uint32_t xstring_appendC (xstring* xstr, char c);

uint32_t xstring_appendS (xstring* xstr, const void* src, uint32_t n);

uint32_t xstring_appendF (xstring* xstr, const char* __restrict __format, ...);

uint32_t xstring_appendN (xstring* xstr, char c, uint32_t n);

#endif //PB_XSTRING_H
