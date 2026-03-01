// TEST: 00041_pos_complex_basic
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2
// STANDARD_TEXT:
// "complex types are optional, but if supported..."
// EXPECT: run_success

#include <complex.h>

int main(void) {
#ifdef __STDC_NO_COMPLEX__
    return 0; // If not supported, we skip it
#else
    double complex z = 1.0 + 2.0 * I;
    if (creal(z) != 1.0) return 1;
    if (cimag(z) != 2.0) return 2;
    return 0;
#endif
}
