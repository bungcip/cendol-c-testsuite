// TEST: 00119_neg_default_outside_switch
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.8.1p1
// STANDARD_TEXT:
// "A default label shall appear only within a switch statement."
// EXPECT: compile_error

int main(void) {
    default: // Error: default outside of switch
        return 0;
}
