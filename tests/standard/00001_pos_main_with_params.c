// TEST: 00001_pos_main_with_params
// CATEGORY: positive
// STANDARD: C11
// REFERENCE: ISO C11 §5.1.2.2.1
// STANDARD_TEXT:
// "... or with two parameters (referred to here as argc and argv)...
// int main(int argc, char *argv[]) { /* ... */ }"
// EXPECT: run_success

int main(int argc, char *argv[]) {
    if (argc < 1) return 1;
    if (argv[0] == 0) return 2;
    return 0;
}
