// TEST: 00049_neg_atomic_bitfield
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.1p5
// STANDARD_TEXT:
// "A bit-field shall have a type that is a qualified or unqualified version 
// of _Bool, signed int, unsigned int, or some other implementation-defined type."
// (And 6.7.2.4p4 "The _Atomic qualifier shall not be used if the type name 
// is an array type or a function type.") -> Actually 6.7.2.1p5 implies limited types.
// EXPECT: compile_error

struct s {
    _Atomic int x : 4; // Error: _Atomic on bit-field
};

int main(void) {
    return 0;
}
