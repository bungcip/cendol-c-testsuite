// TEST: 10021_prescan_pasting
// CATEGORY: preprocessor
// STANDARD: C11

#define PASTE(a, b) a ## b
#define X 1
#define VAR1 42
#define VARX 99

int x = PASTE(VAR, X);
