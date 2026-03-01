// TEST: 00108_neg_include_missing
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.10.2p2
// STANDARD_TEXT:
// "A preprocessing directive of the form # include <h-char-sequence>... 
// searches a sequence of implementation-defined places for a header identified 
// by the specified sequence..."
// EXPECT: compile_error

#include <non_existent_header_xyz.h>

int main(void) {
    return 0;
}
