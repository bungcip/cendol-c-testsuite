// TEST: 10020_double_stringification
// CATEGORY: preprocessor
// STANDARD: C11

#define XSTR(x) STR(x)
#define STR(x) #x
#define VAL hello

char *s = XSTR(VAL);
