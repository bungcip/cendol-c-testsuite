// TEST: 00104_neg_elif_without_if
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.1
// STANDARD_TEXT:
// "Each directive shall be controlled by its corresponding #if..."
// EXPECT: compile_error

#elif 1 // Error: no matching #if

int main(void) {
    return 0;
}
