// TEST: 00010_pos_composite_type_func
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.2.7p3
// STANDARD_TEXT:
// "If two types are compatible, any composite type is also compatible 
// with both... If both types are array types, then... if only one type 
// specifies an element count, then the composite type has that count."
// EXPECT: compile_success

// Compatible declarations of f
void f(int a[]);
void f(int a[10]);
void f(int a[10]) { (void)a; }

// Function pointers
void g(void (*p)(int []));
void g(void (*p)(int [20]));

int main(void) {
    return 0;
}
