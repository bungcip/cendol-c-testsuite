// TEST: 00015_pos_generic_default
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.1.1p2
// STANDARD_TEXT:
// "A generic selection shall have at most one default generic association."
// EXPECT: run_success

int main(void) {
    double d = 1.0;
    const char *s = _Generic(d,
        int: "int",
        default: "other"
    );
    return 0;
}
