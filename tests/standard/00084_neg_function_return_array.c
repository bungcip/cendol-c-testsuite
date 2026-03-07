// TEST: 00084_neg_function_return_array
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.6.3p1
// STANDARD_TEXT:
// "the return type... shall not be an array type or a function type."
// EXPECT: compile_error

int f(void)[10]; // Error: function cannot return an array

int main(void) {
    return 0;
}
