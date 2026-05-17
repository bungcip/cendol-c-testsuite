// TEST: neg_static_init_nonconst
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.9p4
// STANDARD_TEXT:
// "All the expressions in an initializer for an object that has static or 
// thread storage duration shall be constant expressions or string literals."
// EXPECT: compile_error

int main(void) {
    int y = 1;
    static int x = y; // Error: initializer for static object must be constant
    return 0;
}
