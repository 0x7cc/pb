//
// Created by x7cc on 2020/3/11.
//

#ifndef PB_NATIVE_H
#define PB_NATIVE_H

#if __cplusplus
#define PB_DLL_PUBLIC extern "C"
#define PB_LIB_PUBLIC extern "C"
#define PB_PUBLIC PB_LIB_PUBLIC
#else
#define PB_PUBLIC
#endif

#endif //PB_NATIVE_H
