// TEST: 00107_pre_if_0
// CATEGORY: preprocessor
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.1p6
// STANDARD_TEXT:
// "the directively-controlled conditional inclusion directives... shall 
// follow the same rules as the #if directive..."
// EXPECT: run_success

#if 0
#error "This should be skipped"
#endif
int main(void) { return 0; }
