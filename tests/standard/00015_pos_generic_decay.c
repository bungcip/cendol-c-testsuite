// TEST: 00015_pos_generic_decay
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.1.1
// STANDARD_TEXT:
// "The controlling expression... undergo lvalue, array-to-pointer, and 
// function-to-pointer conversion"
// EXPECT: run_success

void f(void) {}

int main(void) {
    int a[10];
    int r1 = _Generic(a, int*: 1, default: 0);
    int r2 = _Generic(f, void (*)(void): 1, default: 0);
    
    if (r1 != 1) return 1;
    if (r2 != 1) return 2;
    return 0;
}
