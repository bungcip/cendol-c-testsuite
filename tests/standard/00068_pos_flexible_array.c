// TEST: 00068_pos_flexible_array
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.1p18
// STANDARD_TEXT:
// "As a special case, the last member of a structure with more than one 
// named member may have an incomplete array type; such a member is called a 
// flexible array member."
// EXPECT: run_success

struct s {
    int n;
    int array[]; // Flexible array member
};

int main(void) {
    if (sizeof(struct s) < sizeof(int)) return 1;
    return 0;
}
