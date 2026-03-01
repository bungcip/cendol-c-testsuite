// TEST: 10030_string_esc_space
// CATEGORY: preprocessor
// STANDARD: C11

#define STR(x) #x
char *s1 = STR(  a    b  );
char *s2 = STR("quote");
char *s3 = STR(  a  \n  b  );
