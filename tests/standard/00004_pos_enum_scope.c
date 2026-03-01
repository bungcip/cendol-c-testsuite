// TEST: 00004_pos_enum_scope
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.2.1p4
// STANDARD_TEXT:
// "If an identifier designates two different entities in the same name space, 
// the scopes might overlap."
// EXPECT: run_success

enum color { RED, GREEN };

int main(void) {
    enum color { BLUE, RED }; // Shadows outer RED
    if (RED != 1) return 1;
    return 0;
}
