// TEST: 10027_macro_clash
// CATEGORY: preprocessor
// STANDARD: C11

#define f(x) x + 1
int f = 10;
int y = f;
int z = f(20);
