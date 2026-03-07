// TEST: 00010_pos_integer_promotion
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.3.1.1p2
// STANDARD_TEXT:
// "If an int can represent all values of the original type (as restricted by 
// the width, for a bit-field), the value is converted to an int; otherwise, 
// it is converted to an unsigned int. These are called the integer promotions."
// EXPECT: run_success

#include <stdbool.h>

#define IS_TYPE(x, T) _Generic((x), T: 1, default: 0)
#define IS_INT(x) IS_TYPE(x, int)
#define IS_UINT(x) IS_TYPE(x, unsigned int)

int main(void) {
    char c = 1;
    signed char sc = 1;
    unsigned char uc = 1;
    short s = 1;
    unsigned short us = 1;
    _Bool b = true;

    // All narrow types should promote to 'int' assuming 32-bit int and 16-bit short
    if (!IS_INT(+c)) return 1;
    if (!IS_INT(+sc)) return 2;
    if (!IS_INT(+uc)) return 3;
    if (!IS_INT(+s)) return 4;
    
    // unsigned short promotes to int if int can hold all values
    // In most 32-bit systems, USHRT_MAX (65535) fits in int.
    if (!IS_INT(+us)) return 5;
    
    if (!IS_INT(+b)) return 6;

    // Promotion happens in arithmetic operations too
    if (!IS_INT(c + c)) return 10;
    if (!IS_INT(us + us)) return 11;

    return 0;
}
