// TEST: 00052_neg_thread_local_auto
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.1p4
// STANDARD_TEXT:
// "In the declaration of an object with block scope, if the declaration 
// specifiers include _Thread_local, they shall also include either static 
// or extern."
// EXPECT: compile_error

int main(void) {
    _Thread_local int x; // Error: block scope _Thread_local must be static or extern
    return 0;
}
