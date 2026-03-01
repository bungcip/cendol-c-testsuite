// TEST: 00082_pos_struct_ptr_init
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.9p11
// STANDARD_TEXT:
// "The initializer for a scalar shall be a single expression, optionally 
// enclosed in braces."
// EXPECT: run_success

struct s { int x; };

int main(void) {
    struct s obj = { 42 };
    struct s *p = &obj;
    if (p->x != 42) return 1;
    return 0;
}
