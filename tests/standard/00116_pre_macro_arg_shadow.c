// TEST: 00116_pre_macro_arg_shadow
// CATEGORY: preprocessor
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.3
// STANDARD_TEXT:
// "A parameter in the replacement list... is replaced by the corresponding 
// argument..."
// EXPECT: run_success

#define SHADOW(x) (x + x)
int main(void) {
    int x = 10;
    if (SHADOW(5) != 10) return 1;
    return 0;
}
