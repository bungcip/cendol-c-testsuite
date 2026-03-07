// TEST: 00011_pos_bitfield_promotion
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.3.1.1p2
// STANDARD_TEXT:
// "If an int can represent all values of the original type (as restricted by 
// the width, for a bit-field), the value is converted to an int; otherwise, 
// it is converted to an unsigned int. These are called the integer promotions."
// EXPECT: run_success

#define IS_TYPE(x, T) _Generic((x), T: 1, default: 0)
#define IS_INT(x) IS_TYPE(x, int)
#define IS_UINT(x) IS_TYPE(x, unsigned int)

struct S {
    unsigned int u1 : 1;
    unsigned int u31 : 31;
    unsigned int u32 : 32;
    signed int s1 : 1;
};

int main(void) {
    struct S s = {0};

    // Assuming 32-bit int:
    // u1 (0..1) fits in int -> int
    if (!IS_INT(+s.u1)) return 1;

    // u31 (0..2^31-1) fits in int (assuming 32-bit int, INT_MAX is 2^31-1) -> int
    if (!IS_INT(+s.u31)) return 2;

    // u32 (0..2^32-1) does NOT fit in int (max 2^31-1) -> unsigned int
    // NOTE: This might depend on the architecture's int size. 
    // If int is 32-bit, this MUST be unsigned int.
    if (!IS_UINT(+s.u32)) return 3;

    // s1 (-1..0) fits in int -> int
    if (!IS_INT(+s.s1)) return 4;

    // Mixed arithmetic with bit-fields
    if (!IS_INT(s.u1 + s.u31)) return 5;
    if (!IS_UINT(s.u1 + s.u32)) return 6;

    return 0;
}
