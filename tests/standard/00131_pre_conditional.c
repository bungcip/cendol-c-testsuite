// TEST: 00131_pre_conditional
// CATEGORY: preprocessor
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.1p1
// STANDARD_TEXT:
// "The expression that controls conditional inclusion shall be an integer 
// constant expression..."
// EXPECT: run_success

#define VALUE 2

#if VALUE == 1
    int x = 1;
#elif VALUE == 2
    int x = 2;
#else
    int x = 0;
#endif

int main(void) { 
    if (x != 2) return 1;
    return 0; 
}
