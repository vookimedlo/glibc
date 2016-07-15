/* Copyright (C) 2016 Free Software Foundation, Inc.
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


/*
 * wrapper exp10f128(x)
 */

#include <math.h>
#include <math_private.h>

_Float128
__exp10f128 (_Float128 x)
{
  _Float128 z = __ieee754_exp10f128 (x);
  if (__builtin_expect (!isfinite (z) || z == 0, 0) && isfinite (x))
    {
      /* exp10f128 overflow if x > 0, underflow if x < 0.  */
       __set_errno (ERANGE);
      return signbit (x) == 0 ? HUGE_VAL_F128 : 0;
    }
  return z;
}
weak_alias (__exp10f128, exp10f128)
