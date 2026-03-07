// TEST: 00134_pos_pre_line_filename
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.4
// EXPECT: run_success

#include <string.h>

int main(void) {
#line 100 "fake_file.c"
    if (__LINE__ != 100) return 1;
    if (strcmp(__FILE__, "fake_file.c") != 0) return 2;
    return 0;
}
