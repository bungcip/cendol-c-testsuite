// TEST: 00120_pre_undef
// CATEGORY: preprocessor
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.3.5p1
// STANDARD_TEXT:
// "A preprocessing directive of the form # undef identifier causes the 
// specified identifier no longer to be defined as a macro name."
// EXPECT: run_success

#define X 1
#undef X

#ifdef X
#error "X should not be defined"
#endif

int main(void) {
    return 0;
}
