// TEST: 00084_pos_alignment
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.5p1
// STANDARD_TEXT:
// "Alignment is a property of an object type that specifies the boundary on 
// which objects of that type are placed..."
// EXPECT: run_success

#include <stdalign.h>
#include <stddef.h>

struct s {
    alignas(16) int x;
};

int main(void) {
    if (alignof(struct s) < 16) return 1;
    return 0;
}
