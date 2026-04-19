// TEST: 00037_pos_logical_and_shortcut
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.13p4
// STANDARD_TEXT:
// "unlike the bitwise binary & operator, the && operator guarantees 
// left-to-right evaluation; there is a sequence point after the evaluation 
// of the first operand."
// EXPECT: run_success

int main(void) {
    int x = 0;
    if (0 && (x = 1)) {}
    if (x != 0) return 1;
    return 0;
}
