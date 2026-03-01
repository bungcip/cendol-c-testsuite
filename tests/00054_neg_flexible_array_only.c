// TEST: 00054_neg_flexible_array_only
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.1p18
// STANDARD_TEXT:
// "the last member of a structure with more than one named member may have 
// an incomplete array type"
// EXPECT: compile_error

struct s {
    int array[]; // Error: must have at least one other named member
};

int main(void) {
    return 0;
}
