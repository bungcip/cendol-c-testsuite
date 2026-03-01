// TEST: 00052_pos_flexible_array_sizeof
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.1p18
// STANDARD_TEXT:
// "the size of the structure is as if the flexible array member were omitted"
// EXPECT: run_success

struct s {
    int n;
    double d;
    int a[];
};

struct s_no_vla {
    int n;
    double d;
};

int main(void) {
    if (sizeof(struct s) != sizeof(struct s_no_vla)) return 1;
    return 0;
}
