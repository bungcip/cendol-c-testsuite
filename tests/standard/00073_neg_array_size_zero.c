// TEST: 00073_neg_array_size_zero
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.6.2p1
// STANDARD_TEXT:
// "the expression... shall have a value greater than 0"
// EXPECT: compile_error

int main(void) {
    int a[0]; // Error: array size must be greater than zero
    return 0;
}
