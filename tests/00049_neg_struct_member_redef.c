// TEST: 00049_neg_struct_member_redef
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.1p12
// STANDARD_TEXT:
// "Within a structure or union specifier, the same identifier shall not 
// appear as the name of more than one member..."
// EXPECT: compile_error

struct s {
    int x;
    int x; // Error: duplicate member
};

int main(void) {
    return 0;
}
