// TEST: 00017_neg_generic_no_match
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.1.1p2
// STANDARD_TEXT:
// "If a generic selection has no default generic association, its controlling 
// expression shall have a type that is compatible with exactly one of the 
// types specified..."
// EXPECT: compile_error

int main(void) {
    double d = 1.0;
    _Generic(d,
        int: 1,
        float: 2
    );
    return 0;
}
