// TEST: 10015_line_splicing
// CATEGORY: preprocessor
// STANDARD: C11

#define MULTILINE \
    int x = 1; \
    int y = 2;

void foo() {
    MULTILINE
}
