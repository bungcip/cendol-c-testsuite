// TEST: 00068_pos_const_volatile
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.3p5
// STANDARD_TEXT:
// "If an object has both const-qualified and volatile-qualified types... 
// it is as if it were present once"
// EXPECT: run_success

int main(void) {
    const volatile int x = 42;
    int y = x;
    if (y != 42) return 1;
    return 0;
}
