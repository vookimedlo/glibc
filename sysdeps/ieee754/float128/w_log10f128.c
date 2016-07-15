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


/* wrapper log10f128(x) */
_Float128
__log10f128 (_Float128 x)
{
  if (__builtin_expect (islessequal (x, 0), 0))
    {
      if (x == 0)
	{
	  feraiseexcept (FE_DIVBYZERO);
	  __set_errno (ERANGE);
	  return -HUGE_VAL_F128;
	}
      else
	{
	  feraiseexcept (FE_INVALID);
	  __set_errno (EDOM);
	  return NAN;
	}
    }
  return  __ieee754_log10f128 (x);
}
weak_alias (__log10f128, log10f128)
