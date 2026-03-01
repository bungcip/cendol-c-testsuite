// TEST: 00125_pre_token_pasting
// CATEGORY: preprocessor
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.3.3p2
// STANDARD_TEXT:
// "If, in the replacement list of a function-like macro, a parameter is 
// immediately preceded or followed by a ## preprocessing token..."
// EXPECT: run_success

#define CONCAT(a, b) a ## b

int main(void) {
    int xy = 10;
    return CONCAT(x, y);
}
