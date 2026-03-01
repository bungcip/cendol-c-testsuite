// TEST: 00036_neg_register_file_scope
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.1p2
// STANDARD_TEXT:
// "register... shall be used only in the declaration of an object... within a block"
// EXPECT: compile_error

register int x; // Error: register at file scope

int main(void) {
    return 0;
}
