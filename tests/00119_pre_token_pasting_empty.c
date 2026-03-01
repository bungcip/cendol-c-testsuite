// TEST: 00119_pre_token_pasting_empty
// CATEGORY: preprocessor
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.3.3p2
// STANDARD_TEXT:
// "If the parameter that is immediately preceded or followed by a ## 
// preprocessing token is replaced by an empty sequence... it is replaced 
// by a placemarker preprocessing token."
// EXPECT: run_success

#define GLUE(x, y) x ## y
int main(void) {
    int GLUE(a, ) = 10; // Result is 'a'
    if (a != 10) return 1;
    return 0;
}
