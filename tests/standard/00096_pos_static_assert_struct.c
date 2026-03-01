// TEST: 00096_pos_static_assert_struct
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.10p1
// STANDARD_TEXT:
// "A static assertion occurs when a _Static_assert declaration is encountered."
// EXPECT: run_success

struct s {
    int x;
    _Static_assert(sizeof(int) >= 2, "int size check in struct");
};

int main(void) {
    return 0;
}
