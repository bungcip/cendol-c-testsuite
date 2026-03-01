// TEST: 00021_neg_void_ptr_arith
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.6p2
// STANDARD_TEXT:
// "For addition, either both operands shall have arithmetic type, or one 
// operand shall be a pointer to a complete object type..." (void is NOT an object type)
// EXPECT: compile_error

int main(void) {
    void *p = 0;
    p = p + 1; // Error: pointer arithmetic on void* is not standard
    return 0;
}
