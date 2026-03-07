// TEST: 00050_neg_bitfield_type
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.1p5
// STANDARD_TEXT:
// "A bit-field shall have a type that is a qualified or unqualified version 
// of _Bool, signed int, unsigned int, or some other implementation-defined 
// type."
// EXPECT: compile_error

struct s {
    float f : 4; // Error: bit-field cannot be float
};

int main(void) {
    return 0;
}
