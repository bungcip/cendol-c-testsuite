// TEST: 00084_pos_const_array_init
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.9p14
// STANDARD_TEXT:
// "An array of character type may be initialized by a character string 
// literal... optionally enclosed in braces."
// EXPECT: run_success

int main(void) {
    const int arr[] = {1, 2, 3};
    if (arr[1] != 2) return 1;
    return 0;
}
