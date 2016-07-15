/* w_lgammaf128.c -- _Float128 version of w_lgamma.c.
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
 * wrapper _Float128 lgammaf128(_Float128 x, int *signgamp)
 */

#include <math.h>
#include <math_private.h>

_Float128
__lgammaf128 (_Float128 x)
{
  _Float128 y = __ieee754_lgammaf128_r (x, &__signgam);
  if (__builtin_expect( !isfinite (y), 0) && isfinite (x))
    {
      __set_errno (ERANGE);
      return HUGE_VAL_F128;
    }
  return y;
}

weak_alias (__lgammaf128, lgammaf128)
