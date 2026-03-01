// TEST: 00123_pre_pragma_op
// CATEGORY: preprocessor
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.9p1
// STANDARD_TEXT:
// "A preprocessing directive of the form _Pragma ( string-literal ) causes the 
// processor to behave as if it were a pragma directive..."
// EXPECT: run_success

_Pragma("GCC diagnostic ignored \"-Wunused-variable\"")

int main(void) {
    int x; // Should not trigger warning in compilers that support it
    return 0;
}
