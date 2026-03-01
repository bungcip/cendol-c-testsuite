// TEST: 00009_pos_complex_arith
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.2.5p11
// EXPECT: run_success

#include <complex.h>
#include <stdio.h>

int main(void) {
    double complex z1 = 1.0 + 2.0*I;
    double complex z2 = 2.0 + 3.0*I;
    
    double complex z3 = z1 + z2;
    if (creal(z3) != 3.0 || cimag(z3) != 5.0) return 1;
    
    double complex z4 = z1 * z2;
    // (1+2i)*(2+3i) = 2 + 3i + 4i + 6i^2 = 2 + 7i - 6 = -4 + 7i
    if (creal(z4) != -4.0 || cimag(z4) != 7.0) return 2;
    
    return 0;
}
