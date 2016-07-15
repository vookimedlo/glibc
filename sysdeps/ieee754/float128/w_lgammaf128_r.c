/* w_lgammaf128_r.c -- _Float128 version of w_lgamma_r.c.
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

/*
 * wrapper _Float128 lgammaf128_r(_Float128 x, int *signgamp)
 */

#include <math.h>
#include <math_private.h>


_Float128
__lgammaf128_r(_Float128 x, int *signgamp)
{
  _Float128 y = __ieee754_lgammaf128_r (x, signgamp);
  if (__builtin_expect (!isfinite (y), 0) && isfinite (x))
    {
      __set_errno (ERANGE);
      return HUGE_VAL_F128;
    }
  return y;
}
weak_alias (__lgammaf128_r, lgammaf128_r)
