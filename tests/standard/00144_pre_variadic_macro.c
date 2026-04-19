// TEST: 00144_pre_variadic_macro
// CATEGORY: preprocessor
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.3p5
// STANDARD_TEXT:
// "If the identifier-list in the macro definition ends with an ellipsis (...) 
// the identifier __VA_ARGS__ shall occur in the replacement list."
// EXPECT: run_success

int printf(const char *format, ...);
#define LOG(...) printf(__VA_ARGS__)

int main(void) {
    LOG("Hello %s\n", "World");
    return 0;
}
