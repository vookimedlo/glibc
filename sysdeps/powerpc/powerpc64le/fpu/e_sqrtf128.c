/* soft-fp sqrt for _Float128
   Return sqrt(a)
   Copyright (C) 1997-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.
   Contributed by Richard Henderson (rth@cygnus.com) and
		  Jakub Jelinek (jj@ultra.linux.cz).

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   In addition to the permissions in the GNU Lesser General Public
   License, the Free Software Foundation gives you unlimited
   permission to link the compiled version of this file into
   combinations with other programs, and to distribute those
   combinations without any restriction coming from the use of this
   file.  (The Lesser General Public License restrictions do apply in
   other respects; for example, they cover modification of the file,
   and distribution when not linked into a combine executable.)

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

/* Unavoidable hacks since TFmode is assumed to be binary128. */
#define TFtype KFtype
#define TF KF

#include <soft-fp.h>
#include <quad.h>

__float128
__ieee754_sqrtf128 (__float128 a)
{
#ifndef _ARCH_PWR9
  FP_DECL_EX;
  FP_DECL_Q (A);
  FP_DECL_Q (R);
  __float128 r;

  FP_INIT_ROUNDMODE;
  FP_UNPACK_Q (A, a);
  FP_SQRT_Q (R, A);
  FP_PACK_Q (r, R);
  FP_HANDLE_EXCEPTIONS;
  return r;
#else
  __float128 z;
  asm ("xssqrtqp %0,%1" : "=wq" (z) : "wq" (a));
  return z;
#endif
}
strong_alias (__ieee754_sqrtf128, __sqrtf128_finite)
