// TEST: 00112_neg_void_return_val
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.8.6.4p1
// STANDARD_TEXT:
// "A return statement with an expression shall not appear in a function 
// whose return type is void."
// EXPECT: compile_error

void f(void) {
    return 42; // Error: return with value in void function
}

int main(void) {
    return 0;
}
