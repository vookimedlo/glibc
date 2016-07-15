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

#include <fenv.h>
#include <math.h>
#include <math_private.h>


/* wrapper j1f128 */
_Float128
__j1f128 (_Float128 x)
{
  return __ieee754_j1f128 (x);
}
weak_alias (__j1f128, j1f128)


/* wrapper y1f128 */
_Float128
__y1f128 (_Float128 x)
{
  if (__builtin_expect (islessequal (x, 0) || isgreater (x, X_TLOSS), 0))
    {
      if (x < 0)
	{
	  /* d = zero/(x-x) */
	  feraiseexcept (FE_INVALID);
	  __set_errno (EDOM);
	  return NAN;
	}
      else if (x == 0)
	{
	  /* d = -one/(x-x) */
	  feraiseexcept (FE_DIVBYZERO);
	  __set_errno (ERANGE);
	  return -HUGE_VAL_F128;
	}
    }
  return __ieee754_y1f128 (x);
}
weak_alias (__y1f128, y1f128)
