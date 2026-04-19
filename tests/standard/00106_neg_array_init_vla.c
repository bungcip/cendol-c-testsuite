// TEST: 00106_neg_array_init_vla
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.9p3
// STANDARD_TEXT:
// "The type of the entity to be initialized shall be an array of unknown 
// size or a complete object type that is not a variable length array type."
// EXPECT: compile_error

int main(void) {
    int n = 10;
    int array[n] = {0}; // Error: cannot initialize VLA
    return 0;
}
