// TEST: 00043_neg_storage_class_on_param
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.1p2
// STANDARD_TEXT:
// "The only storage-class specifier that may occur in a parameter 
// declaration is register."
// EXPECT: compile_error

void f(static int x) {} // Error: static on parameter

int main(void) {
    return 0;
}
```
