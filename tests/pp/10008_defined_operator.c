// TEST: 10008_defined_operator
// CATEGORY: preprocessor
// STANDARD: C11

#define MACRO
#if defined(MACRO) && !defined(OTHER)
int x = 1;
#else
int x = 0;
#endif

#if defined OTHER
int y = 1;
#else
int y = 0;
#endif
