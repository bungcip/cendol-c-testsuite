// TEST: 00123_pre_empty_arg
// CATEGORY: preprocessor
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.3p10
// STANDARD_TEXT:
// "A parameter in the replacement list... is replaced by the corresponding 
// argument after all macros contained therein have been expanded." (Empty args allowed)
// EXPECT: run_success

#define M(x) x
int main(void) {
    int y = M(); // Empty argument
    return 0;
}
