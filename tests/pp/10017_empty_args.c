// TEST: empty_args
// CATEGORY: preprocessor
// STANDARD: C11

#define EMPTY(x) [x]
char *s1 = EMPTY();

#define TWO(x, y) x - y
int val = TWO(,);
