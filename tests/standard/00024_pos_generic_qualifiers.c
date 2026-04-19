// TEST: 00024_pos_generic_qualifiers
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.1.1p2
// STANDARD_TEXT:
// "The type of the controlling expression is the type of the expression 
// as given by 6.3.2.1, which means that l-value to r-value, array to pointer, 
// and function to pointer conversions are performed and any type qualifiers 
// are removed."
// EXPECT: run_success

#define IS_INT(x) _Generic((x), int: 1, default: 0)
#define IS_INT_PTR(x) _Generic((x), int*: 1, default: 0)

int main(void) {
    const int ci = 10;
    volatile int vi = 20;
    int arr[10];

    // 1. Qualifiers are removed from the controlling expression
    if (!IS_INT(ci)) return 1;
    if (!IS_INT(vi)) return 2;
    if (!IS_INT((const volatile int)30)) return 3;

    // 2. Array-to-pointer conversion
    if (!IS_INT_PTR(arr)) return 4;

    // 3. Function-to-pointer conversion
    // _Generic(main, int(*)(void): 1, default: 0) should be 1
    if (!_Generic(main, int(*)(void): 1, default: 0)) return 5;

    return 0;
}
