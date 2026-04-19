// TEST: 00091_neg_vla_static_duration
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.6.2p2
// STANDARD_TEXT:
// "it shall have block scope and no linkage." (objects with static storage duration shall not be VM)
// EXPECT: compile_error

int n = 10;
int array[n]; // Error: VLA at file scope (static storage duration)

int main(void) {
    return 0;
}
