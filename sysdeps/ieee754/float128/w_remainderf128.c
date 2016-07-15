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

#include <math.h>
#include <math_private.h>

static _Float128 zero = 0;

/* wrapper remainderf128 */
_Float128
__remainderf128 (_Float128 x, _Float128 y)
{
  if (((__builtin_expect (y == 0, 0) && !isnan (x))
       || (__builtin_expect (isinf (x), 0) && !isnan (y))))
    {
      __set_errno (EDOM);
      return zero / zero;
    }
  return __ieee754_remainderf128 (x, y);
}
weak_alias (__remainderf128, remainderf128)
