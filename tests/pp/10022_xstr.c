// TEST: 10022_xstr
// CATEGORY: preprocessor
// STANDARD: C11

#define XSTR(s) STR(s)
#define STR(s) #s
#define VALUE 42

char *s1 = STR(VALUE);
char *s2 = XSTR(VALUE);
