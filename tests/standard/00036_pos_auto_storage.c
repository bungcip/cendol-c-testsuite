// TEST: 00036_pos_auto_storage
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.1p1
// STANDARD_TEXT:
// "The storage-class specifiers are: typedef, extern, static, _Thread_local, 
// auto, register."
// EXPECT: run_success

int main(void) {
    auto int x = 10;
    if (x != 10) return 1;
    return 0;
}
