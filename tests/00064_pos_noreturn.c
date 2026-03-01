// TEST: 00064_pos_noreturn
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.4p1
// STANDARD_TEXT:
// "The function specifiers are: inline and _Noreturn."
// EXPECT: run_success

#include <stdnoreturn.h>
#include <stdlib.h>

noreturn void my_exit(int status) {
    exit(status);
}

int main(void) {
    return 0;
}
