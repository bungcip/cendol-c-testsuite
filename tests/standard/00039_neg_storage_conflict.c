// TEST: 00039_neg_storage_conflict
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.1p2
// STANDARD_TEXT:
// "At most one storage-class specifier may be given in the declaration 
// specifiers in a declaration..."
// EXPECT: compile_error

int main(void) {
    // Constraint: at most one storage-class specifier may be given
    static extern int x; 
    return 0;
}
