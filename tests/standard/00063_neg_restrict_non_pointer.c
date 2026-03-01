// TEST: 00063_neg_restrict_non_pointer
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.3p2
// STANDARD_TEXT:
// "Types other than pointer types derived from object or incomplete types 
// shall not be restrict-qualified."
// EXPECT: compile_error

int main(void) {
    int restrict x; // Error: restrict on non-pointer
    return 0;
}
