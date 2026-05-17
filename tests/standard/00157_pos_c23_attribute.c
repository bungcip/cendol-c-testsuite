// TEST: 00157_pos_c23_attribute
// CATEGORY: positive
// STANDARD: C23
// REFERENCE: ISO C23 §6.7.12
// STANDARD_TEXT:
// "Attributes are a mechanism for providing additional information to the implementation..."
// EXPECT: compile_success

[[maybe_unused]] static void f(void) {}

struct [[deprecated]] S {
    int a;
};

int main(void) {
    [[maybe_unused]] int x = 10;
    return 0;
}
