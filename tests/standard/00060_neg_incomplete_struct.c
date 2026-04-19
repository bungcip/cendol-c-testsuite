// TEST: 00060_neg_incomplete_struct
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.1p9
// STANDARD_TEXT:
// "A member of a structure or union may have any complete object type 
// other than a variably modified type."
// EXPECT: compile_error

struct s;
struct t {
    struct s m; // Error: field 'm' has incomplete type
};

int main(void) {
    return 0;
}
