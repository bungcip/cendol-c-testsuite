// TEST: 00057_pos_enum_trailing_comma
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.2p1
// STANDARD_TEXT:
// "enum-specifier: enum identifier { enumerator-list , }..."
// EXPECT: run_success

enum e { A, B, C, };

int main(void) {
    if (C != 2) return 1;
    return 0;
}
