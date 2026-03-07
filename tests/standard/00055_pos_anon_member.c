// TEST: 00055_pos_anon_member
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §6.7.2.1p13
// STANDARD_TEXT:
// "An unnamed member of structure type with no tag is called an anonymous 
// structure; an unnamed member of union type with no tag is called an anonymous union."
// EXPECT: run_success

struct t {
    int x;
    union {
        int y;
        float z;
    };
};

int main(void) {
    struct t obj;
    obj.y = 10; // Direct access to anonymous union member
    if (obj.y != 10) return 1;
    obj.z = 1.0f;
    if (obj.z != 1.0f) return 2;
    return 0;
}
