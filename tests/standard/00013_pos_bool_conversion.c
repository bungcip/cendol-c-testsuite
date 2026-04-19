// TEST: 00013_pos_bool_conversion
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.3.1.2
// STANDARD_TEXT:
// "When any scalar value is converted to _Bool, the result is 0 if the value 
// compares equal to 0; otherwise, the result is 1."
// EXPECT: run_success

#include <stdbool.h>

int main(void) {
    // 1. Integer conversions
    if ((_Bool)0 != 0) return 1;
    if ((_Bool)1 != 1) return 2;
    if ((_Bool)-1 != 1) return 3;
    if ((_Bool)123456 != 1) return 4;

    // 2. Floating-point conversions (IEEE 754)
    volatile double zero = 0.0;
    volatile double neg_zero = -0.0;
    volatile double one = 1.0;
    volatile double neg_one = -1.0;
    
    if ((_Bool)zero != 0) return 10;
    if ((_Bool)neg_zero != 0) return 11;
    if ((_Bool)one != 1) return 12;
    if ((_Bool)neg_one != 1) return 13;
    
    // 3. Infinity and NaN
    // Use volatile to prevent constant folding if the compiler hasn't implemented it correctly yet
    volatile double inf = 1.0 / zero;
    volatile double nan = zero / zero;
    
    // Inf != 0, so should be 1
    if ((_Bool)inf != 1) return 14;
    
    // NaN != 0 (it is not equal to anything, including zero), so should be 1
    if ((_Bool)nan != 1) return 15;

    // 4. Pointers
    void *ptr = (void *)0x1234;
    void *null_ptr = (void *)0;
    
    if ((_Bool)ptr != 1) return 20;
    if ((_Bool)null_ptr != 0) return 21;

    // 5. Direct assignment
    _Bool b;
    b = 0.123;
    if (b != 1) return 30;
    
    b = -0.0;
    if (b != 0) return 31;
    
    b = 42;
    if (b != 1) return 32;

    return 0;
}
