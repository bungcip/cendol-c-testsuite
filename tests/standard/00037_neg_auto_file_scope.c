// TEST: 00037_neg_auto_file_scope
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.1p2
// STANDARD_TEXT:
// "auto... shall be used only in the declaration of an object... within a block"
// EXPECT: compile_error

auto int x; // Error: auto at file scope

int main(void) {
    return 0;
}
