// TEST: 00069_pos_const_ptr
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.3p5
// STANDARD_TEXT:
// "If the same qualifier appears more than once... it is as if it were 
// present once."
// EXPECT: run_success

int main(void) {
    int x = 42;
    const int *p1 = &x;       // pointer to const int
    int *const p2 = &x;       // const pointer to int
    const int *const p3 = &x; // const pointer to const int
    
    if (*p1 != 42) return 1;
    if (*p2 != 42) return 2;
    if (*p3 != 42) return 3;
    
    *p2 = 10;
    if (x != 10) return 4;
    if (*p1 != 10) return 5;
    
    return 0;
}
