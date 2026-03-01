// TEST: 00044_pos_struct_nesting
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.1
// STANDARD_TEXT:
// "A structure or union specifier... optionally a sequence of member 
// declarations."
// EXPECT: run_success

struct outer {
    struct inner {
        int x;
    } i;
};

int main(void) {
    struct outer o;
    o.i.x = 42;
    struct inner in; // struct inner is also available in the scope
    in.x = 10;
    return 0;
}
