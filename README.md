# C11+ Conformance Test Suite

A standard-driven, extensible test suite designed to simplify the development and validation of C compilers.

## Motivation & Purpose

Building a C compiler is a complex task. Ensuring strict adherence to ISO C standards (C11, C17, and beyond) requires thousands of tests covering preprocessor behavior, language semantics, and constraint violations.

The suite currently contains **123 tests** covering various preprocessor, language, and negative constraint scenarios.

The primary goal of this project is to simplify the process for C compiler developers to perform rapid, standardized conformance testing. With its modular infrastructure, developers can easily integrate their compilers and run comprehensive test suites categorized by ISO C specifications.

## ✨ Key Features

- **Extensible Compiler Support**: Add your own compiler by implementing a simple Python adapter (see `runner/adapters/`).
- **Standard-Driven Validation**: Every test case directly references a specific section of the ISO C standard (ISO C11/C17/C23).
- **Three-Tier Testing**:
  - **Preprocessor**: Validates macro expansion, conditionals, and token transformation.
  - **Positive (Runtime)**: Verifies that valid C programs compile and execute with the expected result code.
  - **Negative (Constraint)**: Ensures that invalid code is correctly rejected by the compiler.
- **Black-box Integrity Verification**: Before running tests, the runner performs a two-step sanity check (random return codes and output strings) to ensure the compiler is genuinely executing the code and not just returning success.
- **Ordered by Standard**: All tests are numbered sequentially according to their order in the ISO C11 standard.

## 📁 Directory Structure

- `runner/`: Core engine logic and compiler adapters.
- `tests/`: Standardized test cases named as `NUM_CAT_DESC.c` where `NUM` follows the C11 standard order.
- `scripts/`: CLI entry points and execution logic.
- `docs/`: Guides for extending the suite and writing new tests.
- `output/`: Temporary directory for intermediate compilation artifacts (automatically ignored).

## 🚀 Quick Start

To run the suite with GCC:
```bash
./run.py gcc
```

To run with Clang:
```bash
./run.py clang
```

To run your custom compiler (e.g., Cendol):
```bash
./run.py cendol
```

## 🛠️ Command Line Options

- `compiler {gcc,clang,cendol}`: Select the compiler to test.
- `--category {preprocessor,positive,negative}`: Filter tests by type.
- `--test-num NUM`: Run a specific test number (e.g., `101` for `00101`).
- `--pattern PATTERN`: Run tests matching a substring in their name.
- `--fail-fast`: Stop execution immediately on the first failure.
- `--test-dir DIR`: Specify a custom directory for tests.

## 📚 Documentation

- [Adding a New Compiler](docs/adding_compiler.md)
- [Writing a New Test](docs/writing_tests.md)
- [Integrity Verification Checks](docs/integrity_checks.md)
- [ISO C Reference Guide](docs/reference_guide.md)

## ⚖️ License

MIT. See [LICENSE.md](LICENSE.md) for full details.
Copyright (c) 2026 Gigih Aji Ibrahim.
