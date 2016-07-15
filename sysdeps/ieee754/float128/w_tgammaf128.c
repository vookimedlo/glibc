/* w_tgammaf128.c -- _Float128 version of w_gamma.c.
 */

/*
 * ====================================================
 * Copyright (C) 1993 by Sun Microsystems, Inc. All rights reserved.
 *
 * Developed at SunPro, a Sun Microsystems, Inc. business.
 * Permission to use, copy, modify, and distribute this
 * software is freely granted, provided that this notice
 * is preserved.
 * ====================================================
 */

/* _Float128 gammaf128(_Float128 x)
 * Return the Gamma function of x.
 */

#include <errno.h>
#include <math.h>
#include <math_private.h>

_Float128
__tgammaf128 (_Float128 x)
{
  int local_signgam;
  _Float128 y = __ieee754_gammaf128_r (x, &local_signgam);

  if (__glibc_unlikely (!isfinite (y) || y == 0)
      && (isfinite (x) || (isinf (x) && x < 0)))
    {
      if (x == 0)
	{
	  __set_errno (ERANGE);
	  return __copysignf128 (HUGE_VAL_F128, x);
	}
      else if (__floorf128 (x) == x && x < 0)
	{
	  __set_errno (EDOM);
	  return NAN;
	}
      else if (y == 0)
	{
	  __set_errno (ERANGE); /* tgamma underflow */
	}
      else
	{
	  __set_errno (ERANGE);
	  return __copysignf128 (HUGE_VAL_F128, x);
	}
    }
  return local_signgam < 0 ? - y : y;
}
weak_alias (__tgammaf128, tgammaf128)
