// TEST: 00089_neg_array_size_not_int
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.6.2p1
// STANDARD_TEXT:
// "The expression... shall have an integer type."
// EXPECT: compile_error

int main(void) {
    int a[1.5]; // Error: array size must be integer
    return 0;
}
