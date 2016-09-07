/* Compute 2^x.
   Copyright (C) 2012-2016 Free Software Foundation, Inc.
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

#include <float128_private.h>

_Float128
__ieee754_exp2l (_Float128 x)
{
  if (__glibc_likely (isless (x, (_Float128) FLT128_MAX_EXP)))
    {
      if (__builtin_expect (isgreaterequal (x, (_Float128) (FLT128_MIN_EXP
							    - FLT128_MANT_DIG
							    - 1)), 1))
	{
	  int intx = (int) x;
	  _Float128 fractx = x - intx;
	  _Float128 result;
	  if (fabsl (fractx) < FLT128_EPSILON / 4)
	    result = __scalbnl (1 + fractx, intx);
	  else
	    result = __scalbnl (__ieee754_expl (M_LN2l * fractx), intx);
	  math_check_force_underflow_nonneg (result);
	  return result;
	}
      else
	{
	  /* Underflow or exact zero.  */
	  if (isinf (x))
	    return 0;
	  else
	    return FLT128_MIN * FLT128_MIN;
	}
    }
  else
    /* Infinity, NaN or overflow.  */
    return FLT128_MAX * x;
}
strong_alias (__ieee754_exp2f128, __exp2f128_finite)
