// TEST: 10007_elif
// CATEGORY: preprocessor
// STANDARD: C11

#define VAL 2

#if VAL == 1
int x = 1;
#elif VAL == 2
int x = 2;
#elif VAL == 3
int x = 3;
#else
int x = 0;
#endif
