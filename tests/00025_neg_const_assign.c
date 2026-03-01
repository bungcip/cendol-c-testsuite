// TEST: 00025_neg_const_assign
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.16.1p1
// STANDARD_TEXT:
// "the left operand has atomic, qualified, or unqualified arithmetic type 
// other than a type that is const-qualified"
// EXPECT: compile_error

int main(void) {
    const int x = 10;
    x = 20; // Error: modifying const
    return 0;
}
