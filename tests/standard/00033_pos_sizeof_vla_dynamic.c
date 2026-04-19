// TEST: 00033_pos_sizeof_vla_dynamic
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.3.4p2
// STANDARD_TEXT:
// "If the type of the operand is a variable length array type, the operand 
// is evaluated; otherwise, the operand is not evaluated..."
// EXPECT: run_success

int main(void) {
    int n = 10;
    int array[n];
    if (sizeof(array) != n * sizeof(int)) return 1;
    return 0;
}
