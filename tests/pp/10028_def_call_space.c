// TEST: 10028_def_call_space
// CATEGORY: preprocessor
// STANDARD: C11

#define SPACE_AFTER_NAME (x) x + 100
int val = SPACE_AFTER_NAME (10); // Should expand to (x) x + 100 (10) because it's object-like
