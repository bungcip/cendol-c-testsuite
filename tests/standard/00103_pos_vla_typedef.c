// TEST: 00103_pos_vla_typedef
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.8p3
// STANDARD_TEXT:
// "If the identifier is declared to be a typedef name... and the type 
// contains a variably modified type, then the variably modified type is 
// evaluated each time the declaration is executed."
// EXPECT: run_success

int f(int n) {
    typedef int vla_type[n];
    vla_type a;
    a[0] = 42;
    return a[0];
}

int main(void) {
    return f(10) == 42 ? 0 : 1;
}
