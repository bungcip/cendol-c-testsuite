# Writing a New Test

Each test case is a C source file with a structured metadata header.

## Naming Convention
Every test file must follow the `NNNNN_CAT_DESC.c` format, where:
- `NNNNN`: 5-digit sequence number, ordered by appearance in the C11 standard.
- `CAT`: Category shorthand (`pre`, `pos`, or `neg`).
- `DESC`: Descriptive name of the test.

Example: `00019_pos_alignof_basic.c`

## Metadata Header
```c
// TEST: 00019_pos_alignof_basic
// CATEGORY: preprocessor | positive | negative
// STANDARD: C11 (or C17, C23)
// REFERENCE: ISO C11 §6.x.y.z
// STANDARD_TEXT:
// "Literal text from the standard paragraph..."
// EXPECT: preprocess_success | compile_success | compile_error | run_success
```

## Categories
- **Preprocessor**: Tests for macro expansion, #include, etc.
- **Positive**: Valid C programs that should compile (and optionally run).
- **Negative**: Invalid C programs that must fail compilation.

## Example (Negative Test)
```c
// TEST: 00021_neg_void_ptr_arith
// CATEGORY: negative
// STANDARD: C11
// REFERENCE: ISO C11 §6.5.6p2
// EXPECT: compile_error

int main() {
    int *p;
    void *v;
    return p - v; // Constraint violation
}
```
