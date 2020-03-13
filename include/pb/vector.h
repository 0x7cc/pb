//
// Created by 廖梧平 on 2020/3/13.
//

#ifndef PB_VECTOR_H
#define PB_VECTOR_H

#include <stdint.h>

typedef struct
{
  int16_t x;
  int16_t y;
} vector2;

typedef struct
{
  int16_t x;
  int16_t y;
  int16_t z;
} vector3;

typedef struct
{
  int16_t x;
  int16_t y;
  int16_t z;
  int16_t w;
} vector4;

#endif //PB_VECTOR_H
