// TEST: 10026_paste_recursion
// CATEGORY: preprocessor
// STANDARD: C11

#define PASTE(a, b) a ## b
#define PASTE_EN(a, b) PASTE(a, b)
#define X 1
#define VAR1 99

int v1 = PASTE(VAR, X);
int v2 = PASTE_EN(VAR, X);
