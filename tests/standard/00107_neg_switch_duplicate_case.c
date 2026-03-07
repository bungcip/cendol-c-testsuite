// TEST: 00107_neg_switch_duplicate_case
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.8.4.2p3
// STANDARD_TEXT:
// "The expression of each case label shall be an integer constant expression 
// and no two of the case constant expressions in the same switch statement 
// shall have the same value after conversion."
// EXPECT: compile_error

int main(void) {
    int x = 1;
    switch(x) {
        case 1: break;
        case 1: break; // Error: duplicate case
    }
    return 0;
}
