// TEST: pos_c23_vla_empty_init
// CATEGORY: positive
// STANDARD: C23
// REFERENCE: ISO C23 §6.7.10
// STANDARD_TEXT:
// "The type of the entity to be initialized shall be an array of unknown size or a complete object type
// that is not a variable length array type, or the initializer shall be an empty initializer."
// EXPECT: compile_success

void f(int n) {
    int a[n] = {};      // Valid in C23
    int b[10][n] = {};  // Valid in C23
}

int main(void) {
    f(10);
    return 0;
}
