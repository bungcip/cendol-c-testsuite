// TEST: 00012_pos_usual_arith_conv
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.3.1.8
// STANDARD_TEXT:
// "If the operand that has unsigned integer type has rank greater than or 
// equal to the rank of the type of the other operand, then the operand 
// with signed integer type is converted to the type of the operand with 
// unsigned integer type."
// EXPECT: run_success

#define IS_INT(x) _Generic((x), int: 1, default: 0)
#define IS_UINT(x) _Generic((x), unsigned int: 1, default: 0)
#define IS_ULONG(x) _Generic((x), unsigned long: 1, default: 0)

int main(void) {
    int s = -1;
    unsigned int u = 1;
    
    // 1. Mixing int and unsigned int of same rank
    // Result should be unsigned int
    if (!IS_UINT(s + u)) return 1;
    
    // -1 (0xFFFFFFFF) + 1 = 0 (as unsigned)
    if ((s + u) != 0) return 2;

    // 2. Rank comparison
    long sl = -1L;
    // On many 64-bit systems, long and int are different sizes.
    // If long is larger than int, 'long' can represent all values of 'unsigned int'.
    // Result becomes 'long'.
    // However, on some systems (like 32-bit or Win64), they might have same rank or 
    // int rank might be smaller.
    
    // Let's test consistent rank rules:
    // unsigned int vs signed int -> unsigned int
    if (!IS_UINT(u + 1)) return 3; // Technically 1 is int
    
    // 3. Comparison interaction
    if (s < u) {
        // This should NOT happen if they are promoted to unsigned!
        // -1 as unsigned is UINT_MAX, which is > 1.
        // So (unsigned int)-1 < (unsigned int)1 is FALSE.
        // If s < u is TRUE, it means promotion to unsigned didn't happen for comparison.
        // Wait, 6.3.1.8 says usual arithmetic conversions are applied to operands of 
        // relational operators (6.5.8p3).
        return 4; 
    }

    return 0;
}
