// TEST: 00006_pos_typedef_shadow
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.2.1p4
// STANDARD_TEXT:
// "If an identifier designates two different entities in the same name space, 
// the scopes might overlap. If so, the scope of one entity... will be a 
// strict subset of the scope of the other entity..."
// EXPECT: run_success

typedef int my_type;

int main(void) {
    float my_type = 1.0f; // Shadows typedef in outer scope
    if (sizeof(my_type) != sizeof(float)) return 1;
    return 0;
}
