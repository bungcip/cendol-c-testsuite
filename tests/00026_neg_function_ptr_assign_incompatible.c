// TEST: 00026_neg_function_ptr_assign_incompatible
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.16.1p1
// STANDARD_TEXT:
// "both operands are pointers to qualified or unqualified versions of 
// compatible types"
// EXPECT: compile_error

void f(int a) {}
void (*ptr)(float);

int main(void) {
    ptr = f; // Error: incompatible function pointer assignment
    return 0;
}
