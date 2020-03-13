//
// Created by x7cc on 2020/3/9.
//

#include "internal/xstring.h"
#include "internal/misc.h"

#include <stdlib.h>
#include <memory.h>
#include <stdarg.h>
#include <stdio.h>
#include <assert.h>

xstring* xstring_new (uint32_t max)
{
  xstring* xstr = (xstring*)malloc (sizeof (xstring));
  xstr->cstr    = (char*)calloc (1, max);
  xstr->max     = max;
  xstr->len     = 0;
  return xstr;
}

void xstring_delete (xstring* xstr)
{
  free (xstr->cstr);
  free (xstr);
}

uint32_t xstring_appendC (xstring* xstr, char c)
{
  int len = xstr->max - xstr->len;
  assert (len >= 1);

  xstr->cstr[xstr->len] = c;
  ++xstr->len;

  return 1;
}

uint32_t xstring_appendS (xstring* xstr, const void* src, uint32_t n)
{
  int len = __min (n, xstr->max - xstr->len);
  assert (len == n);

  memcpy (xstr->cstr + xstr->len, src, len);

  xstr->len += len;
  return len;
}

uint32_t xstring_appendF (xstring* xstr, const char* __restrict __format, ...)
{
  va_list args;
  int     maxlen = xstr->max - xstr->len;
  va_start (args, __format);
  int len = vsnprintf (xstr->cstr + xstr->len, maxlen, __format, args);
  assert (len > 0);
  va_end (args);

  xstr->len += len;
  return len;
}

uint32_t xstring_appendN (xstring* xstr, char c, uint32_t n)
{
  int len = __min (n, xstr->max - xstr->len);
  if (len != n)
    len = len;
  assert (len == n);

  for (int i = 0; i < len; ++i)
  {
    xstr->cstr[xstr->len + i] = c;
  }

  xstr->len += len;

  return len;
}
