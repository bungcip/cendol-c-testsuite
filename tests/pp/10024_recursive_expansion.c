// TEST: 10024_recursive_expansion
// CATEGORY: preprocessor
// STANDARD: C11

#define SELF SELF
int x = SELF;

#define A B
#define B A
int y = A;
