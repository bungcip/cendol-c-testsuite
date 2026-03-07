// TEST: 00062_neg_enum_redef
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.2p3
// STANDARD_TEXT:
// "No two enumeration constants of the same enumeration... shall have the 
// same name." (Actually global scope redeclaration)
// EXPECT: compile_error

enum e1 { A };
enum e2 { A }; // Error: redefinition of 'A'

int main(void) {
    return 0;
}
