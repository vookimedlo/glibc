GLIBC_PROVIDES dnl See aclocal.m4 in the top level source directory.
# Local configure fragment for sysdeps/powerpc/powerpc64le.

dnl Require __float128 support on powerpc64le
old_CFLAGS="$CFLAGS"
CFLAGS="$CFLAGS -mfloat128"
AC_CACHE_CHECK([if $CC is sufficient to build libc for powerpc64le],
	       libc_cv_powerpc64le_compiler_ok,
	       AC_COMPILE_IFELSE([AC_LANG_SOURCE([
#include <stdlib.h>
volatile __float128 one = 1.0q;
volatile __float128 two = 2.0q;
int main (void)
{
  if (one + two != 3.0q)
    abort ();
  return 0;
}
])],
				 [libc_cv_powerpc64le_compiler_ok=yes],
				 [libc_cv_powerpc64le_compiler_ok=no]))
AS_IF([test $libc_cv_powerpc64le_compiler_ok != yes],
      critic_missing="$critic_missing GCC is required in version 6.2 or newer for powerpc64le.")
CFLAGS="$old_CFLAGS"

test -n "$critic_missing" && AC_MSG_ERROR([*** $critic_missing])
