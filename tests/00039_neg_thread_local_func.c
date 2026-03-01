// TEST: 00039_neg_thread_local_func
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.1p4
// STANDARD_TEXT:
// "the _Thread_local specifier... shall be used only in the declaration 
// of an object"
// EXPECT: compile_error

_Thread_local void f(void) {} // Error: _Thread_local on function

int main(void) {
    return 0;
}
