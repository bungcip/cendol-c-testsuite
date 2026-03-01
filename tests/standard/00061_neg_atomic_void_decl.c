// TEST: 00061_neg_atomic_void_decl
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.4p3
// EXPECT: compile_error

_Atomic void v; // Error: _Atomic cannot qualify void

int main(void) {
    return 0;
}
