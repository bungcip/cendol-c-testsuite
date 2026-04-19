// TEST: 00095_pos_vla_prototype
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.6.3p7
// STANDARD_TEXT:
// "If the size is an expression that is not a constant expression: if it 
// occurs in a declaration at function prototype scope, it is treated as 
// if it were replaced by *; otherwise... it is a variable length array type."
// EXPECT: run_success

void f(int n, int a[n]);

void f(int n, int a[n]) {
    if (n > 0) a[0] = 42;
}

int main(void) {
    int x[10];
    f(10, x);
    if (x[0] != 42) return 1;
    return 0;
}
