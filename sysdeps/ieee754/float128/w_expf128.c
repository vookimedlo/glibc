/* w_expf128.c -- _Float128 version of w_exp.c.
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
 * wrapper expf128(x)
 */

#include <math.h>
#include <math_private.h>

_Float128
__expf128(_Float128 x)
{
  _Float128 z = __ieee754_expf128 (x);
  if (__glibc_unlikely (!isfinite (z) || z == 0) && isfinite (x))
    {
      __set_errno (ERANGE);
      return signbit (x) == 0 ? HUGE_VAL_F128 : 0;
    }
  return z;
}
hidden_def (__expf128)
weak_alias (__expf128, expf128)
