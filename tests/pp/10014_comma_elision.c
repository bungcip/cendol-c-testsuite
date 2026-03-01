// TEST: 10014_comma_elision
// CATEGORY: preprocessor
// STANDARD: C11

#define LOG(...) printf(__VA_ARGS__)
void foo() {
    LOG("hi", 0);
    LOG("val: %d", 10);
}
