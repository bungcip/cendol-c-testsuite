// TEST: 00081_neg_function_redef
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7p4
// STANDARD_TEXT:
// "All declarations in the same scope that refer to the same object or 
// function shall specify compatible types." (Actually §6.9.1p1 for redef)
// EXPECT: compile_error

void f(void) {}
void f(void) {} // Error: redefinition

int main(void) {
    return 0;
}
