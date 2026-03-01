// TEST: 00072_neg_array_size_negative
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.6.2p1
// STANDARD_TEXT:
// "If the expression... is a constant expression, it shall have a value 
// greater than zero."
// EXPECT: compile_error

int main(void) {
    int a[-1]; // Error: negative array size
    return 0;
}
