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

/* wrapper sqrtf128 */
_Float128
__sqrtf128 (_Float128 x)
{
  if (__builtin_expect (isless (x, 0), 0) && _LIB_VERSION != _IEEE_)
    {
      __set_errno (EDOM);
      return zero / zero;
    }

  return __ieee754_sqrtf128 (x);
}
weak_alias (__sqrtf128, sqrtf128)
