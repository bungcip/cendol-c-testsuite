// TEST: 00066_pos_volatile_qualifier
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.3p7
// STANDARD_TEXT:
// "An object that has volatile-qualified type may be modified in ways 
// unknown to the implementation..."
// EXPECT: run_success

int main(void) {
    volatile int x = 10;
    x = 20;
    if (x != 20) return 1;
    return 0;
}
