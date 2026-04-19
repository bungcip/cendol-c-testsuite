// TEST: 00057_neg_flexible_array_element
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.1p3
// STANDARD_TEXT:
// "a structure [with a FAM] shall not be a member of a structure or an element of an array"
// EXPECT: compile_error

struct fam {
    int len;
    int data[];
};

// Error: FAM struct as member
struct outer {
    struct fam f;
};

// Error: FAM struct as array element
struct fam arr[3];

int main(void) {
    return 0;
}
