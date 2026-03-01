// TEST: 00095_neg_goto_missing_label
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.8.6.1p1
// STANDARD_TEXT:
// "The identifier in a goto statement shall name a label located somewhere 
// in the enclosing function."
// EXPECT: compile_error

int main(void) {
    goto missing; // Error: label 'missing' not defined
    return 0;
}
