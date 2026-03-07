// TEST: 00076_neg_alignas_register
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.5p3
// STANDARD_TEXT:
// "An alignment specifier shall not be used in a declaration of an object 
// with the register storage class."
// EXPECT: compile_error

#include <stdalign.h>

int main(void) {
    alignas(16) register int x; // Error: alignas on register
    return 0;
}
