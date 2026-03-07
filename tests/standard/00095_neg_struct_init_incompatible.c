// TEST: 00095_neg_struct_init_incompatible
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.9p11
// STANDARD_TEXT:
// "The initializer for a scalar shall be a single expression... both operands 
// are pointers... or both are compatible structure or union types."
// EXPECT: compile_error

struct s1 { int x; };
struct s2 { int x; };

int main(void) {
    struct s1 v1 = { 10 };
    struct s2 v2 = v1; // Error: incompatible struct types
    return 0;
}
