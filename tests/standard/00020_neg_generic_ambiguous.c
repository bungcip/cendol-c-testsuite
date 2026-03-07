// TEST: 00020_neg_generic_ambiguous
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.1.1p2
// STANDARD_TEXT:
// "A generic selection shall have at most one default generic association. It 
// shall have at most one generic association with a type name that is compatible..."
// EXPECT: compile_error

int main(void) {
    int i = 0;
    // ERROR: int and int are compatible, multiple matches
    _Generic(i,
        int: 1,
        int: 2
    );
    return 0;
}
