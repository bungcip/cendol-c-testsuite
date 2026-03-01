// TEST: 00003_neg_label_redef
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.2.1
// STANDARD_TEXT:
// "A label... shall be unique in the function in which it appears."
// EXPECT: compile_error

int main(void) {
    label: ;
    label: ; // Error: duplicate label
    return 0;
}
