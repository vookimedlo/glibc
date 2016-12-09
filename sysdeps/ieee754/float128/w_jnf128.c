/* w_jnf128.c -- _Float128 version of w_jn.c.
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
 * wrapper jn(int n, _Float128 x), yn(int n, _Float128 x)
 * floating point Bessel's function of the 1st and 2nd kind
 * of order n
 *
 * Special cases:
 *	y0(0)=y1(0)=yn(n,0) = -inf with division by zero signal;
 *	y0(-ve)=y1(-ve)=yn(n,-ve) are NaN with invalid signal.
 * Note 2. About jn(n,x), yn(n,x)
 *	For n=0, j0(x) is called,
 *	for n=1, j1(x) is called,
 *	for n<x, forward recursion us used starting
 *	from values of j0(x) and j1(x).
 *	for n>x, a continued fraction approximation to
 *	j(n,x)/j(n-1,x) is evaluated and then backward
 *	recursion is used starting from a supposed value
 *	for j(n,x). The resulting value of j(0,x) is
 *	compared with the actual value to correct the
 *	supposed value of j(n,x).
 *
 *	yn(n,x) is similar in all respects, except
 *	that forward recursion is used for all
 *	values of n>1.
 *
 */

#include <math.h>
#include <math_private.h>

_Float128
__jnf128 (int n, _Float128 x)
{
  return __ieee754_jnf128 (n, x);
}
weak_alias (__jnf128, jnf128)

_Float128
__ynf128 (int n, _Float128 x)	/* wrapper ynf128 */
{
  _Float128 z = __ieee754_ynf128 (n, x);
  if (isnan (x))
    return z;

  if (x <= 0)
    {
      if (x == 0)
	{
	  /* d= -one/(x-x); */
	  __set_errno (ERANGE);
	  return n < 0 && (n & 1) != 0 ? HUGE_VAL_F128 : -HUGE_VAL_F128;
	}
      else
	{
	  /* d = zero/(x-x); */
	  __set_errno (EDOM);
	  return NAN;
	}
    }
  return z;
}
weak_alias (__ynf128, ynf128)
