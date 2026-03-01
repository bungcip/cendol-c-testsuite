// TEST: 00002_pos_main_no_params
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §5.1.2.2.1
// STANDARD_TEXT:
// "The function called at program startup is named main... It shall be 
// defined... with no parameters: int main(void) { /* ... */ }"
// EXPECT: run_success

int main(void) {
    return 0;
}
