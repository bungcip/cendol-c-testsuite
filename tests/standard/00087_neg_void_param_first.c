// TEST: 00087_neg_void_param_first
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.6.3p10
// EXPECT: compile_error

void f(void, int x) {} // Error: void must be the only parameter

int main(void) {
    return 0;
}
