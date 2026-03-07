// TEST: 00052_neg_bitfield_zero_width_named
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.1p11
// STANDARD_TEXT:
// "A bit-field declaration with no declarator, but only a colon and a 
// width, indicates an unnamed bit-field... shall have a width of zero 
// to signal that no further bit-field is to be packed... A bit-field 
// with a name... shall have a width that is non-zero."
// EXPECT: compile_error

struct s {
    int x : 0; // Error: named bit-field must have non-zero width
};

int main(void) {
    return 0;
}
