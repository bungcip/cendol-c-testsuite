# Integrity Verification Checks

To ensure that a compiler is genuinely executing the code and not just returning a success exit code (0), the test runner performs a preliminary **Integrity Verification** phase before running the main test suite.

## How it Works

The `TestEngine` performs two distinct checks using randomly generated values to prevent hard-coded "cheating" by a compiler.

### 1. Random Return Code Verification
The runner generates a minimal C program that returns a random integer between 10 and 100:
```c
int main(void) { return <RANDOM_CODE>; }
```
It then compiles and executes this program, verifying that the actual exit code matches the expected random value.

### 2. Random Output String Verification
The runner generates a C program that prints a random 16-character alphanumeric string to `stdout` without using the preprocessor:
```c
int puts(const char *s);
int main(void) {
    puts("<RANDOM_STRING>");
    return 0;
}
```
It compiles and executes this program, verifying that the expected string is present in the compiler's output.

## Why it Matters
Since this test suite operates as a black-box validator, it relies on the honesty of the compiler's return codes and standard output. These checks ensure that:
- The compiler actually generates and links a functional executable.
- The environment allows the execution of generated binaries.
- The compiler isn't "faking" success for valid C programs.

If either check fails, the test suite will halt immediately with an **INTEGRITY ERROR**.
