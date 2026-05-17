// TEST: neg_alignas_func_def
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.5p3
// STANDARD_TEXT:
// "An alignment specifier shall not appear in a declaration of... a function."
// EXPECT: compile_error

_Alignas(8) void f(void) { } // Error: _Alignas on function definition

int main(void) {
    return 0;
}
