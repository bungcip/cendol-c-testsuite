// TEST: 10029_computed_include
// CATEGORY: preprocessor
// STANDARD: C11

#define HEADER "tests/pp/10029_dummy.h"
#include HEADER

int x = DUMMY_VAL;
