// TEST: 00017_pos_generic
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.1.1p1
// STANDARD_TEXT:
// "A generic selection shall have the following syntax: _Generic ( 
// assignment-expression , generic-assoc-list )"
// EXPECT: run_success

#include <string.h>

#define get_type(x) _Generic((x), \
    int: "int", \
    float: "float", \
    default: "other" \
)

int main(void) {
    int i = 0;
    float f = 0.0;
    if (strcmp(get_type(i), "int") != 0) return 1;
    if (strcmp(get_type(f), "float") != 0) return 2;
    if (strcmp(get_type(1.0), "other") != 0) return 3;
    return 0;
}
