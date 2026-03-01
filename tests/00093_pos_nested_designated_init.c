// TEST: 00093_pos_nested_designated_init
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.9
// EXPECT: run_success

struct Inner {
    int x;
    int y;
};

struct Outer {
    struct Inner in;
    int a[3];
};

int main(void) {
    struct Outer o = {
        .in = { .y = 42 },
        .a = { [1] = 7 }
    };
    
    if (o.in.y != 42) return 1;
    if (o.in.x != 0) return 2;
    if (o.a[1] != 7) return 3;
    if (o.a[2] != 0) return 4;
    
    return 0;
}
