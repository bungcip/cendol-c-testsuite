// TEST: 00136_pre_macro_redef
// CATEGORY: preprocessor
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.3p2
// STANDARD_TEXT:
// "An identifier currently defined as an object-like macro shall not be 
// redefined by another #define preprocessing directive unless the second 
// definition is an object-like macro definition and the two replacement 
// lists are identical."
// EXPECT: run_success

#define X 1
#define X 1

int main(void) {
    return X - 1;
}
