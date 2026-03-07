// TEST: 00111_neg_continue_outside_loop
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.8.6.2p1
// STANDARD_TEXT:
// "A continue statement shall appear only in or as a loop body."
// EXPECT: compile_error

int main(void) {
    continue; // Error: continue outside of loop
    return 0;
}
