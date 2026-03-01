// TEST: 00078_pos_vla_local
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.6.2p4
// STANDARD_TEXT:
// "If the size is an expression that is not an integer constant expression... 
// each time it is evaluated it shall have a value greater than zero."
// EXPECT: run_success

int main(void) {
    int n = 10;
    int array[n];
    array[0] = 42;
    if (array[0] != 42) return 1;
    return 0;
}
