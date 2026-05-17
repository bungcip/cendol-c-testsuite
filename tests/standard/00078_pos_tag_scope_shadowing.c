// TEST: pos_tag_scope_shadowing
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.3p3
// STANDARD_TEXT:
// "A declaration of the form struct-or-union identifier ; specifies a structure or union type and declares the identifier as a tag, that will be defined later in the same scope."
// EXPECT: run_success

struct A {
    int a;
    int b;
};

int main(void) {
    struct A; // Declares/shadows tag A in the current scope
    struct A {
        double x;
    } obj;
    obj.x = 2.0;
    if (sizeof(obj) != sizeof(double)) return 1;
    return 0;
}
