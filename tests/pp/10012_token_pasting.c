// TEST: 10012_token_pasting
// CATEGORY: preprocessor
// STANDARD: C11

#define CONCAT(a, b) a ## b
int xy = 100;
int z = CONCAT(x, y);
