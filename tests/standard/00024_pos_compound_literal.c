// TEST: 00024_pos_compound_literal
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.2.5p3
// STANDARD_TEXT:
// "A postfix expression that consists of a parenthesized type name followed 
// by a brace-enclosed list of initializers is a compound literal."
// EXPECT: run_success

struct s { int x; int y; };

int main(void) {
    struct s obj;
    obj = (struct s){1, 2};
    if (obj.x != 1 || obj.y != 2) return 1;
    return 0;
}
