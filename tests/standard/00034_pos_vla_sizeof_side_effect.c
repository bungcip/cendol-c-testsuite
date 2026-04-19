// TEST: 00034_pos_vla_sizeof_side_effect
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.3.4p2
// STANDARD_TEXT:
// "If the type of the operand is a variable length array type, the operand 
// is evaluated; otherwise, the operand is not evaluated and the result 
// is an integer constant."
// EXPECT: run_success

#include <stddef.h>

int main(void) {
    int n = 5;
    // sizeof should evaluate its operand because it's a VLA type.
    size_t s = sizeof(int[n++]);
    
    if (n != 6) return 1;
    if (s != 5 * sizeof(int)) return 2;
    
    return 0;
}
