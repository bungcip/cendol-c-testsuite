// TEST: 10025_indirect_recursion
// CATEGORY: preprocessor
// STANDARD: C11

#define A(x) x B
#define B(y) y A
int x = A(1)(2)(3);
