# Adding a New Compiler

To support a new compiler, you need to implement a subclass of `CompilerAdapter` (found in `runner/compiler.py`).

## 1. Using `GccLikeAdapter` (Recommended)

If your compiler uses command-line flags similar to GCC or Clang (e.g., `-E` for preprocessing, `-o` for output, `-c` for compile-only), you can use the `GccLikeAdapter` base class to minimize boilerplate.

1. Create a new file in `runner/adapters/` (e.g., `mycc.py`).
2. Inherit from `GccLikeAdapter`:

   ```python
   from runner.compiler import GccLikeAdapter

   class MyCCAdapter(GccLikeAdapter):
       def __init__(self):
           super().__init__(
               name="mycc",
               path="/path/to/mycc",
               extra_args=["--std", "c11", "-Wall"] # Add any default flags
           )
   ```

## 2. Implementing a Custom Adapter

If your compiler has a unique CLI, inherit directly from `CompilerAdapter`.

1. Create a new file in `runner/adapters/` (e.g., `custom_cc.py`).
2. Implement the `CompilerAdapter` interface:

   ```python
   from runner.compiler import CompilerAdapter, CompilationResult
   import subprocess

   class CustomCCAdapter(CompilerAdapter):
       def get_name(self) -> str:
           return "custom_cc"

       def preprocess(self, source_file: str, output_file: str) -> CompilationResult:
           # Implement custom preprocessing logic
           pass

       def compile(self, source_file: str, output_file: str, is_executable: bool = True) -> CompilationResult:
           # Implement custom compilation logic
           pass
   ```

## 3. Registering the Compiler

After creating the adapter, you must register it in `scripts/test.py`:

1. Import your adapter at the top:
   ```python
   from runner.adapters.mycc import MyCCAdapter
   ```
2. Add it to the `argparse` choices:
   ```python
   parser.add_argument("compiler", choices=["gcc", "clang", "cendol", "mycc"], ...)
   ```
3. Instantiate it in the `main()` function:
   ```python
   if args.compiler == "mycc":
       compiler = MyCCAdapter()
   ```

Now you can run tests with:
```bash
./run.py mycc --test-num 00001
```
