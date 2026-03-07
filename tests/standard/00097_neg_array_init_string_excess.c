// TEST: 00097_neg_array_init_string_excess
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.9p14
// STANDARD_TEXT:
// "the number of characters in the string literal... shall not exceed 
// the number of elements in the array (excluding the terminating null character 
// if the array is large enough)." (Actually if it's too small for the non-null chars)
// EXPECT: compile_error

int main(void) {
    char s[2] = "abc"; // Error: string too long for array of 2
    return 0;
}
