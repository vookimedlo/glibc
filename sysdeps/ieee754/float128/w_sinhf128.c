/* w_sinhf128.c -- _Float128 version of w_sinh.c.
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
 * wrapper sinhf128(x)
 */

#include <math.h>
#include <math_private.h>

static _Float128 zero = 0.0;

_Float128
__sinhf128 (_Float128 x)
{
  _Float128 z = __ieee754_sinhf128 (x);
  if (__builtin_expect (!isfinite (z), 0) && isfinite (x))
    {
      __set_errno (ERANGE);
      return x > zero ? HUGE_VAL_F128 : -HUGE_VAL_F128;
    }
  return z;
}
weak_alias (__sinhf128, sinhf128)
