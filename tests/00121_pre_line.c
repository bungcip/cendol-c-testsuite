// TEST: 00121_pre_line
// CATEGORY: preprocessor
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.4p1
// STANDARD_TEXT:
// "A preprocessing directive of the form # line digit-sequence causes the 
// implementation to imagine... that the line number of the following source 
// line is the specified digit-sequence."
// EXPECT: run_success

#line 100 "new_filename.c"
int main(void) {
#if __LINE__ != 101
#error "Line number should be 101"
#endif
    return 0;
}
