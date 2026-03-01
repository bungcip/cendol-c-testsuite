// TEST: 00092_neg_array_init_excess
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.9p22
// STANDARD_TEXT:
// "If an array of unknown size is initialized, its size is determined by the 
// largest indexed designator..." (and for known size) "the number of 
// initializers shall not exceed the number of elements."
// EXPECT: compile_error

int main(void) {
    int a[2] = {1, 2, 3}; // Error: too many initializers
    return 0;
}
