// TEST: 00072_pos_alignas_type
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.5p4
// STANDARD_TEXT:
// "An alignment specifier may be an initial _Alignas followed by a 
// parenthesized type name..."
// EXPECT: run_success

#include <stdalign.h>

struct s {
    alignas(double) int x;
};

int main(void) {
    return 0;
}
