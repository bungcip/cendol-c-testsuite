// TEST: 00077_neg_void_parameter_named
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.6.3p10
// STANDARD_TEXT:
// "the identifier list declares no parameters... if it consists of a 
// single parameter of type void, such a parameter shall not be named."
// EXPECT: compile_error

void f(void x) {} // Error: named void parameter

int main(void) {
    return 0;
}
