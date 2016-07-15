/* w_acoshf128.c -- _Float128 version of w_acosh.c.
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
 * wrapper coshf128(x)
 */

#include <math.h>
#include <math_private.h>

_Float128
__coshf128 (_Float128 x)
{
  _Float128 z = __ieee754_coshf128 (x);
  if (__builtin_expect (!isfinite (z), 0) && isfinite (x))
    {
      __set_errno (ERANGE);
      return HUGE_VAL_F128;
    }
  return z;
}
weak_alias (__coshf128, coshf128)
