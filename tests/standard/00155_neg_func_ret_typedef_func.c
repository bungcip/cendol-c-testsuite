// TEST: 00155_neg_func_ret_typedef_func
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.6.3p1
// STANDARD_TEXT:
// "the return type... shall not be an array type or a function type."
// EXPECT: compile_error

typedef void F(void);
F f(void); // Error: function cannot return a function type

int main(void) {
    return 0;
}
