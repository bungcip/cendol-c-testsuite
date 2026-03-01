// TEST: 00104_neg_break_outside_loop
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.8.6.2p1
// STANDARD_TEXT:
// "A break statement shall appear only in or as a switch body or a loop body."
// EXPECT: compile_error

int main(void) {
    break; // Error: break outside of loop/switch
    return 0;
}
