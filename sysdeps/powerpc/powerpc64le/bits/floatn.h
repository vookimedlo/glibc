/* Macros to control TS 18661-3 glibc features on PPC64.
   Copyright (C) 2016 Free Software Foundation, Inc.
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

#define __GLIBC_INTERNAL_STARTING_HEADER_IMPLEMENTATION
#include <bits/libc-header-start.h>

/* The runtime supports the type.  */
#define __HAVE_FLOAT128 1

/* Only set the enable flag if float128 is actually supported on the
   building toolchain. (i.e -mfloat128 on a newer toolchain.)  */
#define __USE_FLOAT128 __GLIBC_USE (IEC_60559_TYPES_EXT) \
	&& __GNUC_PREREQ (6,2) && defined __FLOAT128__

/* Add a typedef for older GCC compilers which don't natively support
   _Float128 and _Complex _Float128.  */
#if __USE_FLOAT128 && __GNUC_PREREQ (6,2) && !__GNUC_PREREQ(7,0) \
    && !defined __CFLOAT128
typedef __float128 _Float128;
typedef _Complex float __cfloat128 __attribute__ ((mode (KC)));
# define __CFLOAT128 __cfloat128
#endif
