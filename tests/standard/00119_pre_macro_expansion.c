// TEST: 00119_pre_macro_expansion
// CATEGORY: preprocessor
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.3p2
// STANDARD_TEXT:
// "An object-like macro is defined by a #define preprocessing directive that 
// includes no parenthesized identifier list."
// EXPECT: run_success

#define PLUS(a, b) ((a) + (b))
int main(void) {
    return PLUS(1, 2) - 3;
}
