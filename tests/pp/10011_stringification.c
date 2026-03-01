// TEST: 10011_stringification
// CATEGORY: preprocessor
// STANDARD: C11

#define STR(x) #x
char *s = STR(hello world);
