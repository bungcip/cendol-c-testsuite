// TEST: 10037_counter_macro_pasting
// CATEGORY: preprocessor
// STANDARD: C11

#define STRINGIFY(x) #x
#define PASTE(x, y) x ## y
#define EVAL(x) x

STRINGIFY(__COUNTER__)
PASTE(x, __COUNTER__)
EVAL(__COUNTER__)
