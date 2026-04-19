// TEST: 00044_pos_thread_local
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.1p1
// STANDARD_TEXT:
// "The storage-class specifiers are: typedef, extern, static, _Thread_local, 
// auto, register."
// EXPECT: run_success

#include <threads.h>

_Thread_local int thread_var = 42;

int main(void) {
    if (thread_var != 42) return 1;
    return 0;
}
