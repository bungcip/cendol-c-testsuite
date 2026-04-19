// TEST: 00117_pos_static_assert_file
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.10p2
// EXPECT: compile_success

_Static_assert(sizeof(int) >= 2, "int must be at least 16-bit");

int main(void) {
    return 0;
}
