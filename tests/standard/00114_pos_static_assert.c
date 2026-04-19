// TEST: 00114_pos_static_assert
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.10p1
// STANDARD_TEXT:
// "A static assertion occurs when a _Static_assert declaration is encountered."
// EXPECT: run_success

_Static_assert(sizeof(int) >= 2, "int must be at least 16 bits");

int main(void) {
    return 0;
}
