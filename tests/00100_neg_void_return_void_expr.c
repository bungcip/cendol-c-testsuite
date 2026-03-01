// TEST: 00100_neg_void_return_void_expr
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.8.6.4p3
// STANDARD_TEXT:
// "A return statement with an expression shall not appear in a function 
// whose return type is void." (Even if the expression is void type)
// EXPECT: compile_error

void g(void) {}

void f(void) {
    return g(); // Error in C (but valid in C++)
}

int main(void) {
    return 0;
}
