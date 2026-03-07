// TEST: 00085_neg_void_param_second
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.6.3p10
// STANDARD_TEXT:
// "If the parameter-type-list contains... void... it shall be the only parameter"
// EXPECT: compile_error

void f(int x, void) {} // Error: void must be the only parameter

int main(void) {
    return 0;
}
