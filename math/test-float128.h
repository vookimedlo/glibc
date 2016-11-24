/* Common definitions for libm tests for _Float128.

   Copyright (C) 2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#define FUNC(function) function ## f128
#define PRINTF_EXPR "e"
#define PRINTF_XEXPR "a"
#define PRINTF_NEXPR "f"
#define BUILD_COMPLEX(real, imag) (CMPLXF128 ((real), (imag)))
#define PREFIX FLT128
#define TYPE_STR "float128"
#define LITM(x) x ## f128
#define FTOSTR strfromf128
#define snan_value_MACRO SNANF128

/* Fixup builtins and constants for older compilers.  */
#include <features.h>
#if !__GNUC_PREREQ (7, 0)
# define __builtin_nanf128 __builtin_nanq
# define __builtin_nansf128 __builtin_nansq
# define __builtin_inff128 __builtin_infq
# define LIT(x) (x ## Q)
# define FLOAT __float128
# define CFLOAT __CFLOAT128
#else
# define LIT(x) (x ## f128)
# define FLOAT _Float128
#endif

#include "test-math-floatn.h"

/* Similarly, finitef128 is not API */
extern int __finitef128 (__float128);

static inline int
finitef128(__float128 f)
{
  return __finitef128 (f);
}
