// TEST: 10016_macro_comments
// CATEGORY: preprocessor
// STANDARD: C11

#define MACRO(x) x /* comment */ + 1
int y = MACRO(10);

#define MULTI(x) x \
    /* first line */ \
    + /* second line */ \
    2
int z = MULTI(20);
