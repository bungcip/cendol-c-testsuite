// TEST: 00033_pos_register_storage
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.1p1
// STANDARD_TEXT:
// "The storage-class specifiers are: typedef, extern, static, _Thread_local, 
// auto, register."
// EXPECT: run_success

int main(void) {
    register int x = 10;
    return 0;
}
