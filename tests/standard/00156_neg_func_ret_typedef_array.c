// TEST: 00156_neg_func_ret_typedef_array
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.6.3p1
// STANDARD_TEXT:
// "the return type... shall not be an array type or a function type."
// EXPECT: compile_error

typedef int A[10];
A h(void); // Error: function cannot return an array type

int main(void) {
    return 0;
}
