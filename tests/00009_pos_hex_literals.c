// TEST: 00009_pos_hex_literals
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.4.4.1
// STANDARD_TEXT:
// "A hexadecimal constant consists of the prefix 0x or 0X followed by a 
// sequence of the hexadecimal digits..."
// EXPECT: run_success

int main(void) {
    int x = 0x123;
    int y = 0xabc;
    if (x != 291) return 1;
    if (y != 2748) return 2;
    return 0;
}
