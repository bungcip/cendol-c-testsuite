// TEST: 10023_combined_ops
// CATEGORY: preprocessor
// STANDARD: C11

#define COMBINE(a, b) #a #b " " a ## b
char *s = COMBINE(foo, bar);
