// TEST: 00013_pos_generic
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.1.1p1
// STANDARD_TEXT:
// "A generic selection shall have the following syntax: _Generic ( 
// assignment-expression , generic-assoc-list )"
// EXPECT: run_success

#define get_type(x) _Generic((x), \
    int: "int", \
    float: "float", \
    default: "other" \
)

int main(void) {
    int i = 0;
    float f = 0.0;
    const char *si = get_type(i);
    const char *sf = get_type(f);
    return 0;
}
