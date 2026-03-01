// TEST: 10019_token_paste_rescan
// CATEGORY: preprocessor
// STANDARD: C11

#define PASTE(a, b) a ## b
#define FOO 42
int x = PASTE(FO, O);
