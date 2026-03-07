// TEST: 00066_pos_typedef_redef_same
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7p3
// STANDARD_TEXT:
// "a typedef name... may be redefined to denote the same type as it 
// currently does"
// EXPECT: run_success

typedef int T;
typedef int T;

int main(void) {
    T x = 0;
    return x;
}
