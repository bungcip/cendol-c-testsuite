// TEST: 00050_neg_bitfield_named_zero_width
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.1p11
// STANDARD_TEXT:
// "A bit-field with a name... shall have a width that is non-zero."
// EXPECT: compile_error

struct s {
    int x : 0; // Error: named bit-field must have non-zero width
};

int main(void) {
    return 0;
}
