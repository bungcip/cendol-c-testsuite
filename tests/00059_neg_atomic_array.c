// TEST: 00059_neg_atomic_array
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.4p3
// STANDARD_TEXT:
// "The _Atomic specifier shall not be used if the type name is an array type 
// or a function type."
// EXPECT: compile_error

int main(void) {
    typedef int array_type[10];
    _Atomic array_type a; // Error: _Atomic on array type
    return 0;
}
