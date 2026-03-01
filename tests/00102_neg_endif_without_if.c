// TEST: 00102_neg_endif_without_if
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.1
// STANDARD_TEXT:
// "Each directive shall be controlled by its corresponding #if..."
// EXPECT: compile_error

#endif // Error: no matching #if

int main(void) {
    return 0;
}
