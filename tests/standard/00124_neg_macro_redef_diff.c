// TEST: 00124_neg_macro_redef_diff
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.3p2
// STANDARD_TEXT:
// "An identifier currently defined as an object-like macro shall not be 
// redefined by another #define preprocessing directive unless... the two 
// replacement lists are identical."
// EXPECT: compile_error

#define X 1
#define X 2 // Error: redefined with different value

int main(void) {
    return 0;
}
