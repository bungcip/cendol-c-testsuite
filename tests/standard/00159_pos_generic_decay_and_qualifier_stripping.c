// TEST: 00159_pos_generic_decay_and_qualifier_stripping
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.1.1
// STANDARD_TEXT:
// "Before comparison, array and function types decay to pointers. Cast types are unqualified."
// EXPECT: run_success

typedef int T[4];
int f(T t) {
    // Both controlling expression parameter 't' and association type 'T' decay to 'int*'
    return _Generic(t, T: 1);
}

int main(void) {
    // 1. Casts lose qualifiers, so typeof((int const)0) is 'int'
    int c1 = _Generic((__typeof((int const)0)*)0, int*: 1);

    // 2. Statement expression in generic selection is evaluated
    int c2 = _Generic(({ 0; }), default: 1);

    // 3. Pointer to complete and incomplete array are compatible, yielding composite pointer type
    int c3 = _Generic(0 ? (int (*)[4])0 : (int (*)[])0, int (*)[4]: 1);

    if (c1 != 1) return 1;
    if (c2 != 1) return 2;
    if (c3 != 1) return 3;

    return 0;
}
