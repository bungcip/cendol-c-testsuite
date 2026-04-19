// TEST: 00028_pos_compound_literal_init
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.2.5
// STANDARD_TEXT:
// "A postfix expression that consists of a parenthesized type name 
// followed by a brace-enclosed list of initializers is a compound literal. 
// It provides an unnamed object whose value is given by the initializer list."
// EXPECT: run_success

struct S {
    int x;
    int y;
};

// 1. Compound literal with static duration (at file scope)
// The initializers must be constant expressions.
int *p = (int[]){1, 2, 3};
struct S *sp = &(struct S){.x = 10, .y = 20};

int main(void) {
    if (p[0] != 1 || p[1] != 2 || p[2] != 3) return 1;
    if (sp->x != 10 || sp->y != 20) return 2;

    // 2. Compound literal with automatic duration
    int *q = (int[]){4, 5, 6};
    if (q[0] != 4 || q[1] != 5 || q[2] != 6) return 3;

    // 3. Modifying a compound literal (not const)
    (int[]){1, 2, 3}[0] = 9;
    
    // 4. Nested compound literals
    struct {
        int a;
        struct S b;
    } s = {1, (struct S){2, 3}};
    
    if (s.a != 1 || s.b.x != 2 || s.b.y != 3) return 4;

    return 0;
}
