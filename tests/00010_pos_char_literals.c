// TEST: 00010_pos_char_literals
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.4.4.4
// STANDARD_TEXT:
// "An integer character constant is a sequence of one or more multibyte 
// characters enclosed in single-quotes..."
// EXPECT: run_success

int main(void) {
    int c1 = 'a';
    int c2 = '\n';
    int c3 = '\x41';
    if (c1 != 97) return 1;
    if (c3 != 65) return 2;
    return 0;
}
