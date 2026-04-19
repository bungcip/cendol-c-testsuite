// TEST: 00097_pos_array_qualifiers_param
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.6.3p7
// STANDARD_TEXT:
// "The [ and ] may optionally contain type qualifiers and the keyword 
// static."
// EXPECT: compile_success

void f(int a[const volatile 10]);

void f(int a[const volatile 10]) {
    (void)a;
}

int main(void) {
    int x[10];
    f(x);
    return 0;
}
