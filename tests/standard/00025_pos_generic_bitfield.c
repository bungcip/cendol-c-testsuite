// TEST: 00025_pos_generic_bitfield
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.1.1p2, §6.3.2.1p3
// STANDARD_TEXT:
// "The type of the controlling expression is the type of the expression as 
// it would have been after lvalue conversion... are applied."
// "if an int can represent all values of the original type... the value 
// is converted to an int; otherwise, it is converted to an unsigned int. 
// These are called the integer promotions."
// EXPECT: run_success

struct S {
    int a : 3;
    unsigned int b : 3;
};

int main(void) {
    struct S s = {0, 0};
    
    // s.a is a bitfield of type int. Integer promotion makes it int.
    if (_Generic(s.a, int: 1, default: 0) != 1) return 1;
    
    // s.b is a bitfield of type unsigned int. Integer promotion makes it int (if it fits).
    // In C11, bit-fields of type _Bool, int, signed int, or unsigned int 
    // undergo integer promotion.
    if (_Generic(s.b, int: 1, unsigned int: 2, default: 0) == 0) return 2;
    
    return 0;
}
