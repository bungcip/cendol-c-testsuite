// TEST: 00048_neg_struct_vla
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.1p3
// STANDARD_TEXT:
// "A structure or union shall not contain a member with a variably modified type."
// EXPECT: compile_error

void f(int n) {
    struct s {
        int a[n]; // Error: VLA not allowed in struct
    };
}

int main(void) {
    return 0;
}
