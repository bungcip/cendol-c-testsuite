// TEST: 00149_neg_error
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.5p1
// STANDARD_TEXT:
// "A preprocessing directive of the form # error pp-tokens causes the 
// implementation to produce a diagnostic message that includes the specified 
// tokens."
// EXPECT: compile_error

#error manual error

int main(void) {
    return 0;
}
