// TEST: 00008_pos_static_addr
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.2.4p3
// STANDARD_TEXT:
// "An object whose identifier is declared with external or internal linkage... 
// has static storage duration. Its lifetime is the entire execution of the 
// program..."
// EXPECT: run_success

static int x = 42;
static int *p = &x;

int main(void) {
    if (*p != 42) return 1;
    return 0;
}
