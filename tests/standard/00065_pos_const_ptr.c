// TEST: 00065_pos_const_ptr
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.3p5
// STANDARD_TEXT:
// "If the same qualifier appears more than once... it is as if it were 
// present once."
// EXPECT: run_success

int main(void) {
    int x = 0;
    const int *p1 = &x;       // pointer to const int
    int *const p2 = &x;       // const pointer to int
    const int *const p3 = &x; // const pointer to const int
    return 0;
}
