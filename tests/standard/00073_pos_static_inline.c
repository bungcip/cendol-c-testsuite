// TEST: 00073_pos_static_inline
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.4p3
// STANDARD_TEXT:
// "A function declared with an inline function specifier is an inline function."
// EXPECT: run_success

static inline int add(int a, int b) {
    return a + b;
}

int main(void) {
    return add(1, 2) - 3;
}
