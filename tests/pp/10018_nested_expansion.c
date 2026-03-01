// TEST: 10018_nested_expansion
// CATEGORY: preprocessor
// STANDARD: C11

#define INNER 10
#define OUTER INNER + 5
int x = OUTER;
