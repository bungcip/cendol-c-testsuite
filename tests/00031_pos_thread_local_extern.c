// TEST: 00031_pos_thread_local_extern
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.1
// STANDARD_TEXT:
// "The storage-class specifiers are: typedef, extern, static, _Thread_local, 
// auto, register."
// EXPECT: run_success

_Thread_local int x;
extern _Thread_local int x;

int main(void) {
    return 0;
}
