#ifndef _COMPLEX_H
# include <math/complex.h>

# ifndef _ISOMAC
/* Return the complex inverse hyperbolic sine of finite nonzero Z,
   with the imaginary part of the result subtracted from pi/2 if ADJ
   is nonzero.  */
extern complex float __kernel_casinhf (complex float z, int adj);
extern complex double __kernel_casinh (complex double z, int adj);
extern complex long double __kernel_casinhl (complex long double z, int adj);
#  if __USE_FLOAT128
#   ifdef __CFLOAT128
extern __CFLOAT128 __kernel_casinhf128 (__CFLOAT128 z, int adj);
#   else
extern _Complex _Float128 __kernel_casinhf128 (_Complex _Float128 z, int adj);
#   endif
#  endif
# endif

#endif
