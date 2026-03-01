// TEST: 00085_neg_typedef_redef_diff
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.8p3
// STANDARD_TEXT:
// "If a typedef name is redefined in the same scope... the types shall be 
// compatible."
// EXPECT: compile_error

typedef int T;
typedef float T; // Error: incompatible redefinition

int main(void) {
    return 0;
}
