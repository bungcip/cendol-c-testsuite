// TEST: 00030_neg_void_variable
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7p7
// STANDARD_TEXT:
// "If an identifier... is declared as an object, it shall have a complete 
// object type by the end of its declarator..." (void is incomplete)
// EXPECT: compile_error

int main(void) {
    void x; // Error: variable cannot be void
    return 0;
}
