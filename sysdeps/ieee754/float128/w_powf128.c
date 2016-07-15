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

/* wrapper powf128 */
_Float128
__powf128 (_Float128 x, _Float128 y)
{
  _Float128 z = __ieee754_powf128 (x, y);
  if (__glibc_unlikely (!isfinite (z)))
    {
      if (isfinite (x) && isfinite (y))
	{
	  if (isnan (z))
	    {
	      /* pow neg**non-int */
	      __set_errno (EDOM);
	      return zero / zero;
	    }
	  else if (x == 0 && y < 0)
	    {
	      __set_errno (ERANGE);
	      return signbit (x) && signbit (z) ?
		     -HUGE_VAL_F128 : HUGE_VAL_F128;
	    }
	  else
	    {
	      /* pow overflow */
	      _Float128 retval = HUGE_VAL_F128;
	      y *= __f128 (0.5);
	      if (x < 0 && __rintf128 (y) != y)
		retval = -HUGE_VAL_F128;
	      __set_errno (ERANGE);
	      return retval;
	    }
	}
    }
  else if (__builtin_expect (z == 0, 0)
	   && isfinite (x) && x != 0 && isfinite (y))
    {
      /* pow underflow */
      _Float128 retval = 0;
      y *= __f128 (0.5);
      if (x < 0 && __rintf128 (y) != y)
	retval = __f128 (-0.0);
      __set_errno (ERANGE);
      return retval;
    }
  return z;
}
weak_alias (__powf128, powf128)
