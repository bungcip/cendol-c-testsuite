// TEST: 00019_pos_alignof_basic
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.3.4
// STANDARD_TEXT:
// "The _Alignof operator yields the alignment requirement of its operand type."
// EXPECT: run_success

#include <stddef.h>

int main(void) {
    size_t a = _Alignof(int);
    size_t b = _Alignof(char);
    if (b != 1) return 1;
    if (a < 1) return 2;
    return 0;
}
