// TEST: 00085_neg_alignment_invalid
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.5p2
// STANDARD_TEXT:
// "A value of an alignment shall be a non-negative integral power of two."
// EXPECT: compile_error

#include <stdalign.h>

struct s {
    // Alignment must be a non-negative integral power of two
    alignas(3) int x; 
};

int main(void) {
    return 0;
}
