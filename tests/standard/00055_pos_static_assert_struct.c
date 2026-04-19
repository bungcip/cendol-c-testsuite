// TEST: 00055_pos_static_assert_struct
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.1
// STANDARD_TEXT:
// "A struct-declaration-list... can contain a static_assert-declaration."
// EXPECT: compile_success

struct S {
    int a;
    _Static_assert(1, "ok");
    int b;
};

int main(void) {
    return 0;
}
