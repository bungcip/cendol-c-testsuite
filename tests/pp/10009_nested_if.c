// TEST: 10009_nested_if
// CATEGORY: preprocessor
// STANDARD: C11

#define A
#define B

#ifdef A
    #ifdef B
        int x = 1;
    #else
        int x = 2;
    #endif
#else
    int x = 3;
#endif
