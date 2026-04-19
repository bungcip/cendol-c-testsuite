// TEST: 00042_pos_comma_operator
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.17p2
// STANDARD_TEXT:
// "The left operand of a comma operator is evaluated as a void expression; 
// there is a sequence point after its evaluation."
// EXPECT: run_success

int main(void) {
    int x = 0;
    int y = (x = 1, x + 1);
    if (y != 2) return 1;
    return 0;
}
