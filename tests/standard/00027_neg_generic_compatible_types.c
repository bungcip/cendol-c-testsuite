// TEST: 00027_neg_generic_compatible_types
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.1.1p2
// STANDARD_TEXT:
// "No two generic associations in the same generic selection shall 
// specify compatible types."
// EXPECT: compile_error

int main(void) {
    int a[10];
    // int(*)[] and int(*)[10] are compatible types.
    // Specifying both in _Generic is a constraint violation.
    return _Generic(&a, int(*)[10]: 1, int(*)[]: 2);
}
