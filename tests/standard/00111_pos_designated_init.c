// TEST: 00111_pos_designated_init
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.9p17
// STANDARD_TEXT:
// "Each designator list begins with its first designator of the form . identifier..."
// EXPECT: run_success

struct s { int x; int y; };

int main(void) {
    struct s obj = { .y = 10, .x = 5 };
    if (obj.x != 5 || obj.y != 10) return 1;
    return 0; // Fixed from 888
}
