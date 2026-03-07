// TEST: 00105_neg_case_outside_switch
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.8.1p1
// STANDARD_TEXT:
// "A case label shall appear only within a switch statement."
// EXPECT: compile_error

int main(void) {
    case 1: // Error: case outside of switch
        return 0;
}
