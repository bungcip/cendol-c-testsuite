// TEST: 00101_neg_duplicate_param
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.6.3p15
// STANDARD_TEXT:
// "If the declarator... includes a parameter type list... each identifier 
// in the identifier list shall be unique."
// EXPECT: compile_error

void f(int x, int x) {} // Error: same parameter name used twice

int main(void) {
    return 0;
}
