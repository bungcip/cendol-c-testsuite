// TEST: 10032_unterminated_macro
// CATEGORY: preprocessor
// EXPECT: fail
// STANDARD: C11

#define f(x) x
int y = f(1
