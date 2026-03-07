// TEST: 00114_pre_empty_hash
// CATEGORY: preprocessor
// STANDARD: C11
// REFERENCE: ISO C11 §6.10p1
// STANDARD_TEXT:
// "A preprocessing directive of the form # [newline] has no effect."
// EXPECT: run_success

#
#  
int main(void) {
    return 0;
}
