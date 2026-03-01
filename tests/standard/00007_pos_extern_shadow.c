// TEST: 00007_pos_extern_shadow
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.2.2p4
// STANDARD_TEXT:
// "For an identifier declared with the storage-class specifier extern... 
// the linkage is the same as the linkage of the prior declaration..."
// EXPECT: run_success

int x = 42;

int main(void) {
    int x = 10;
    {
        extern int x; // Refers to global x
        if (x != 42) return 1;
    }
    return 0;
}
