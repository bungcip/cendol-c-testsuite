// TEST: neg_static_func_block_scope
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.1p7
// STANDARD_TEXT:
// "The declaration of an identifier for a function that has block scope shall 
// have no storage-class specifier other than extern."
// EXPECT: compile_error

int main(void) {
    static int f(void); // Error: static function in block scope
    return 0;
}
