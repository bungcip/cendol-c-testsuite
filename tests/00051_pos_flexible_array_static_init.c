// TEST: 00051_pos_flexible_array_static_init
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.1p18
// STANDARD_TEXT:
// "Initialization of a structure with a flexible array member... 
// is implementation-defined." (Check if it compiles)
// EXPECT: run_success

struct s { int n; int a[]; };

int main(void) {
    struct s obj;
    return 0;
}
