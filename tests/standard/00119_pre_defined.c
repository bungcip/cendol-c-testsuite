// TEST: 00119_pre_defined
// CATEGORY: preprocessor
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.1p1
// STANDARD_TEXT:
// "The unary operator defined... shall have the form: defined identifier 
// or defined ( identifier )"
// EXPECT: run_success

#define YES
int main(void) {
#if !defined(YES)
#error "YES should be defined"
#endif
#if defined(NO)
#error "NO should not be defined"
#endif
    return 0;
}
