// TEST: 00005_pos_struct_tag_scope
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.2.1p4
// STANDARD_TEXT:
// "Each name space... has its own scope."
// EXPECT: run_success

struct s { int x; };

int main(void) {
    struct s { float y; }; // Shadows outer struct tag
    struct s obj;
    obj.y = 1.0f;
    return 0;
}
