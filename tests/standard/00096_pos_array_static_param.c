// TEST: 00096_pos_array_static_param
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.6.3p7
// STANDARD_TEXT:
// "The keyword static within the [ and ]... indicates that at the 
// commencement of each execution of the function, the value of the 
// actual argument shall provide access to the first element of an 
// array with at least as many elements as specified by the size expression."
// EXPECT: compile_success

void f(int a[static 10]);

void f(int a[static 10]) {
    (void)a;
}

int main(void) {
    int x[10];
    f(x);
    return 0;
}
