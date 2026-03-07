// TEST: 00016_pos_generic_expr
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.1.1
// EXPECT: run_success

int main(void) {
    int x = 5;
    char* s = _Generic(x + 1.0, 
        double: "double", 
        int: "int", 
        default: "other"
    );
    
    if (s[0] == 'd' && s[1] == 'o') return 0;
    return 1;
}
