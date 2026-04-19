// TEST: 00116_neg_static_assert_fail
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.10p2
// STANDARD_TEXT:
// "If the value of the constant expression is zero, the implementation shall 
// produce a diagnostic message..."
// EXPECT: compile_error

_Static_assert(1 == 0, "failure expected");

int main(void) {
    return 0;
}
