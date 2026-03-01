// TEST: 00120_pre_function_macro
// CATEGORY: preprocessor
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.3p4
// STANDARD_TEXT:
// "A function-like macro is defined by a #define preprocessing directive that 
// has a parenthesized identifier list."
// EXPECT: run_success

#define SQUARE(x) ((x) * (x))

int main(void) {
    return SQUARE(5) - 25;
}
