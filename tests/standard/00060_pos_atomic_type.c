// TEST: 00060_pos_atomic_type
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.4p1
// STANDARD_TEXT:
// "The _Atomic specifier or qualifier specifier may be used..."
// EXPECT: run_success

#include <stdatomic.h>

int main(void) {
    _Atomic int a = 10;
    atomic_init(&a, 20);
    if (atomic_load(&a) != 20) return 1;
    return 0;
}
