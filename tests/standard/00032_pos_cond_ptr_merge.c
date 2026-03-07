// TEST: 00032_pos_cond_ptr_merge
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.15
// STANDARD_TEXT:
// "If both the second and third operands are pointers or one is a null 
// pointer constant and the other is a pointer, the result type is a 
// pointer to a type qualified with all the type qualifiers of the types 
// pointed-to by both operands."
// EXPECT: run_success

#include <stddef.h>

#define IS_VOID_PTR(x) _Generic((x), void*: 1, default: 0)
#define IS_INT_PTR(x) _Generic((x), int*: 1, default: 0)
#define IS_CONST_INT_PTR(x) _Generic((x), const int*: 1, default: 0)

int main(void) {
    int x = 1;
    int *p = &x;
    const int *cp = &x;
    void *v = &x;

    // 1. Comparison of pointer and void* -> void*
    if (!IS_VOID_PTR(1 ? p : v)) return 1;
    if (!IS_VOID_PTR(0 ? p : v)) return 2;

    // 2. Comparison of int* and const int* -> const int*
    if (!IS_CONST_INT_PTR(1 ? p : cp)) return 3;
    if (!IS_CONST_INT_PTR(0 ? p : cp)) return 4;

    // 3. Comparison of pointer and NULL -> pointer type
    if (!IS_INT_PTR(1 ? p : NULL)) return 5;
    if (!IS_INT_PTR(0 ? p : NULL)) return 6;
    
    // NULL (0) as literal
    if (!IS_INT_PTR(1 ? p : 0)) return 7;

    // 4. Multiple qualifiers
    const volatile int *cvp = &x;
    // Result should be const volatile int*
    if (!_Generic((1 ? cp : cvp), const volatile int*: 1, default: 0)) return 8;

    return 0;
}
