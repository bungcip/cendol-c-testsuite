// TEST: 00013_pos_generic_const_match
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.1.1p2
// STANDARD_TEXT:
// "The type... shall be compatible with exactly one of the types specified..."
// EXPECT: run_success

int main(void) {
    const int x = 1;
    int y = _Generic(x, 
        const int: 1,
        int: 2,
        default: 0
    );
    // Note: Controlling expression undergoes lvalue conversion, which strips qualifiers.
    // So 'const int x' becomes 'int' for matching.
    if (y != 2) return 1;
    return 0;
}
