// TEST: 00025_pos_unary_plus
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.3.3
// STANDARD_TEXT:
// "The operand of the unary + operator shall have arithmetic type; the result 
// is the value of the operand."
// EXPECT: run_success

int main(void) {
    int x = 10;
    int y = +x;
    if (y != 10) return 1;
    return 0;
}
