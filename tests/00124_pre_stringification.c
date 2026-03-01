// TEST: 00124_pre_stringification
// CATEGORY: preprocessor
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.3.2p1
// STANDARD_TEXT:
// "Each occurrence of # followed by a parameter in the replacement list of a 
// function-like macro is replaced by a string literal..."
// EXPECT: run_success

#define STR(x) #x

char *s = STR(hello world);

int main(void) {
    return 0;
}
