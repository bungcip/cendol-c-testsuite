// TEST: 00088_pos_static_assert_block
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.10
// STANDARD_TEXT:
// "A static_assert declaration may occur wherever a declaration can occur."
// EXPECT: run_success

int main(void) {
    _Static_assert(1 + 1 == 2, "Math still works");
    return 0;
}
