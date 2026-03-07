// TEST: 00061_pos_enum_init
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.2p3
// STANDARD_TEXT:
// "The expression that defines the value of an enumeration constant shall 
// be an integer constant expression that has a value representable as an int."
// EXPECT: run_success

enum color {
    RED = 1,
    GREEN = 10,
    BLUE
};

int main(void) {
    if (RED != 1) return 1;
    if (GREEN != 10) return 2;
    if (BLUE != 11) return 3;
    return 0;
}
