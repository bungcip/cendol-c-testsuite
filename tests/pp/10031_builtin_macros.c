// TEST: 10031_builtin_macros
// CATEGORY: preprocessor
// STANDARD: C11

int line1 = __LINE__;
int line2 = __LINE__;

#if __STDC__
int stdc = 1;
#endif
