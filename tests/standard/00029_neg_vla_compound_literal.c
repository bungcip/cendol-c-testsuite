// TEST: 00029_neg_vla_compound_literal
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.2.5p1
// STANDARD_TEXT:
// "The type name shall specify a complete object type or an array of 
// unknown size, but not a variable length array type."
// EXPECT: compile_error

int main(void) {
    int n = 3;
    // Compound literal with VLA type is forbidden in C11
    int *p = (int[n]){1, 2, 3};
    return 0;
}
