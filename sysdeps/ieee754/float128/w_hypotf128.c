/* w_hypotf128.c -- _Float128 version of w_hypot.c.
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
 * wrapper hypotf128(x,y)
 */

#include <math.h>
#include <math_private.h>

_Float128
__hypotf128(_Float128 x, _Float128 y)
{
  _Float128 z;
  z = __ieee754_hypotf128 (x,y);
  if(__builtin_expect (!isfinite (z), 0) && isfinite (x) && isfinite (y))
    {
      __set_errno (ERANGE);
      return HUGE_VAL_F128;
    }
  return z;
}
weak_alias (__hypotf128, hypotf128)
