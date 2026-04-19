// TEST: 10033_defer_expansion
// CATEGORY: preprocessor
// STANDARD: C11

#define EXPAND(...) __VA_ARGS__
#define A_I() A
#define A() A_I () 1
EXPAND(EXPAND(A()))
