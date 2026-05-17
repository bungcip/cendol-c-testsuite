// TEST: 10036_directive_in_macro_args
// CATEGORY: preprocessor
// STANDARD: C11

#define BUILD_ARRAY(x, y, z) { x, y, z }
#define USE_FEATURE_B 1

int my_array[] = BUILD_ARRAY(
    10,
#if USE_FEATURE_B
    20,
#else
    99,
#endif
    30
);
