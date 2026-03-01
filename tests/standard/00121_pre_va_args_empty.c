// TEST: 00121_pre_va_args_empty
// CATEGORY: preprocessor
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.3p5
// STANDARD_TEXT:
// "the identifier __VA_ARGS__ shall occur in the replacement list... it 
// shall be replaced by the directively-unexpanded preprocessing tokens 
// of the arguments..."
// EXPECT: run_success

#define PRINT(...) #__VA_ARGS__
int main(void) {
    const char *s = PRINT();
    return 0;
}
