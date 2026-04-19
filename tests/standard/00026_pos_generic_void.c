// TEST: 00026_pos_generic_void
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.1.1p2
// STANDARD_TEXT:
// "The controlling expression shall be an expression of a complete object 
// type, or the void type."
// EXPECT: run_success

int main(void) {
    // controlling expression is void type.
    // Associations cannot be void, but default can match.
    if (_Generic((void)0, default: 1) != 1) return 1;
    
    return 0;
}
