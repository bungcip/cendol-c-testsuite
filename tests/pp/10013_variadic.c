// TEST: 10013_variadic
// CATEGORY: preprocessor
// STANDARD: C11

#define LOG(...) __VA_ARGS__
int a = LOG(1, 2, 3);
