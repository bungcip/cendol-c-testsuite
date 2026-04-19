// TEST: 00036_neg_pointer_sub_incompatible
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.6p3
// STANDARD_TEXT:
// "For subtraction, one of the following shall hold:... both operands are 
// pointers to qualified or unqualified versions of compatible object types"
// EXPECT: compile_error

int main(void) {
    int *p1 = 0;
    float *p2 = 0;
    int x = p1 - p2; // Error: source types are not compatible
    return 0;
}
