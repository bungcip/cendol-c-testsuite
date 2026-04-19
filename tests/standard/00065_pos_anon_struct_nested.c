// TEST: 00065_pos_anon_struct_nested
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.1p13
// STANDARD_TEXT:
// "The members of an anonymous structure or union are considered to be 
// members of the containing structure or union, keeping their structure 
// or union layout."
// EXPECT: run_success

struct S {
    struct {
        int a;
        struct {
            int b;
        };
    };
    int c;
};

int main(void) {
    struct S s;
    s.a = 1;
    s.b = 2;
    s.c = 3;
    
    if (s.a != 1) return 1;
    if (s.b != 2) return 2;
    if (s.c != 3) return 3;
    
    return 0;
}
