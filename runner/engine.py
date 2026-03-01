import os
import re
import random
import string
from typing import List, Dict, Optional
from runner.compiler import CompilerAdapter, CompilationResult

class TestCase:
    def __init__(self, file_path: str):
        self.file_path = file_path
        self.name = ""
        self.category = ""
        self.standard = ""
        self.reference = ""
        self.expect = ""
        self.diag_pattern = ""
        self._parse_metadata()

    def _parse_metadata(self):
        with open(self.file_path, 'r') as f:
            content = f.read(1024) # Only read the beginning for metadata
            
        metadata = {
            "TEST": "name",
            "CATEGORY": "category",
            "STANDARD": "standard",
            "REFERENCE": "reference",
            "EXPECT": "expect",
            "DIAG_PATTERN": "diag_pattern"
        }
        
        for line in content.splitlines():
            for key, attr in metadata.items():
                match = re.search(fr"// {key}:\s*(.*)", line)
                if match:
                    setattr(self, attr, match.group(1).strip())

class TestEngine:
    def __init__(self, compiler: CompilerAdapter, output_dir: str = "output"):
        self.compiler = compiler
        self.output_dir = output_dir
        if not os.path.exists(self.output_dir):
            os.makedirs(self.output_dir)

    def _get_output_path(self, test_file: str, extension: str) -> str:
        base_name = os.path.basename(test_file)
        return os.path.join(self.output_dir, base_name + extension)

    def discover_tests(self, root_dir: str) -> List[TestCase]:
        test_files = []
        for root, _, files in os.walk(root_dir):
            for file in files:
                if file.endswith(".c"):
                    test_files.append(os.path.join(root, file))
        
        # Sort tests such that those in tests/pp directory come last
        def sort_key(path):
            is_pp = 1 if "tests/pp" in path else 0
            return (is_pp, path)

        test_files.sort(key=sort_key)
        return [TestCase(f) for f in test_files]

    def verify_compiler_integrity(self) -> None:
        """
        Runs preliminary tests to ensure the compiler actually executes code
        and isn't just returning 0 for every command.
        """
        # 1. Test random return code
        expected_code = random.randint(10, 100)
        source_ret = f"int main(void) {{ return {expected_code}; }}"
        test_file_ret = os.path.join(self.output_dir, "_sanity_ret.c")
        exe_file_ret = os.path.join(self.output_dir, "_sanity_ret.exe")
        
        try:
            with open(test_file_ret, 'w') as f: f.write(source_ret)
            comp_res = self.compiler.compile(test_file_ret, exe_file_ret, is_executable=True)
            if not comp_res.success:
                raise Exception(f"Sanity check failed: Could not compile basic return test.\n{comp_res.stderr}")
            
            run_res = self.compiler.run(exe_file_ret)
            if run_res.returncode != expected_code:
                raise Exception(f"Sanity check failed: Compiler is dishonest about return codes.\n"
                                f"Expected {expected_code}, got {run_res.returncode}")
        finally:
            if os.path.exists(test_file_ret): os.remove(test_file_ret)
            if os.path.exists(exe_file_ret): os.remove(exe_file_ret)

        # 2. Test random output string
        expected_str = ''.join(random.choices(string.ascii_letters + string.digits, k=16))
        source_out = f'int puts(const char *s);\nint main(void) {{ puts("{expected_str}"); return 0; }}'
        test_file_out = os.path.join(self.output_dir, "_sanity_out.c")
        exe_file_out = os.path.join(self.output_dir, "_sanity_out.exe")
        
        try:
            with open(test_file_out, 'w') as f: f.write(source_out)
            comp_res = self.compiler.compile(test_file_out, exe_file_out, is_executable=True)
            if not comp_res.success:
                raise Exception(f"Sanity check failed: Could not compile basic output test.\n{comp_res.stderr}")
            
            run_res = self.compiler.run(exe_file_out)
            if expected_str not in run_res.stdout:
                raise Exception(f"Sanity check failed: Compiler is dishonest about stdout.\n"
                                f"Expected to find '{expected_str}', got '{run_res.stdout.strip()}'")
        finally:
            if os.path.exists(test_file_out): os.remove(test_file_out)
            if os.path.exists(exe_file_out): os.remove(exe_file_out)

    def run_test(self, test: TestCase) -> Dict:
        result = {
            "test": test.name,
            "file": os.path.basename(test.file_path),
            "passed": False,
            "message": ""
        }

        if test.category == "preprocessor":
            return self._run_preprocessor_test(test, result)
        elif test.category == "positive":
            return self._run_positive_test(test, result)
        elif test.category == "negative":
            return self._run_negative_test(test, result)
        
        result["message"] = f"Unknown test category: {test.category}"
        return result

    def _run_preprocessor_test(self, test: TestCase, result: Dict) -> Dict:
        out_file = self._get_output_path(test.file_path, ".i")
        
        # Determine if this is a "pure" preprocessor test based on its location
        is_pure = "tests/pp" in test.file_path
        
        comp_res = self.compiler.preprocess(test.file_path, out_file, pure=is_pure)

        if not comp_res.success:
            result["message"] = f"Preprocessing failed (code {comp_res.returncode}):\n{comp_res.stderr}\n{comp_res.stdout}".strip()
            return result

        expected_file = test.file_path + ".expected"
        if os.path.exists(expected_file):
            with open(out_file, 'r') as f:
                actual = f.read()
            with open(expected_file, 'r') as f:
                expected = f.read()

            if is_pure:
                # Normalize tokens: split by whitespace and join with single space
                import re
                def normalize(text):
                    # Split by whitespace and punctuation, but keep punctuation as tokens
                    tokens = re.findall(r"[\w']+|[^\w\s]", text)
                    return " ".join(tokens)
                
                if normalize(expected) == normalize(actual):
                    result["passed"] = True
                else:
                    result["message"] = f"Preprocessor output does not match expectation.\nExpected: {normalize(expected)}\nActual:   {normalize(actual)}"
                    if os.path.exists(out_file): os.remove(out_file)
                    return result
            else:
                # Standard substring match for old preprocessor tests
                if expected.strip() in actual.strip():
                    result["passed"] = True
                else:
                    result["message"] = "Preprocessor output does not match expectation"
                    if os.path.exists(out_file): os.remove(out_file)
                    return result
        else:
            result["passed"] = True

        if os.path.exists(out_file): os.remove(out_file)

        # If the test also expects to be runnable, run it as a positive test
        if test.expect == "run_success":
            return self._run_positive_test(test, result)

        return result

    def _run_positive_test(self, test: TestCase, result: Dict) -> Dict:
        result["passed"] = False # Reset passed status for positive test phase
        exe_file = self._get_output_path(test.file_path, ".exe")
        comp_res = self.compiler.compile(test.file_path, exe_file, is_executable=True)
        
        if not comp_res.success:
            result["message"] = f"Compilation failed (code {comp_res.returncode}):\n{comp_res.stderr}\n{comp_res.stdout}".strip()
            return result

        if not os.path.exists(exe_file):
            result["message"] = f"Compilation succeeded but no executable was produced (expected binary at {exe_file}).\nOutput:\n{comp_res.stderr}\n{comp_res.stdout}".strip()
            return result

        if test.expect == "run_success":
            run_res = self.compiler.run(exe_file)
            if run_res.success:
                result["passed"] = True
            else:
                result["message"] = f"Execution failed with code {run_res.returncode}:\n{run_res.stderr}\n{run_res.stdout}".strip()
        else:
            result["passed"] = True

        if os.path.exists(exe_file): os.remove(exe_file)
        return result

    def _run_negative_test(self, test: TestCase, result: Dict) -> Dict:
        # Negative tests should NOT become executables usually, but we check compilation failure
        obj_file = self._get_output_path(test.file_path, ".o")
        comp_res = self.compiler.compile(test.file_path, obj_file, is_executable=False)
        
        if comp_res.success:
            result["message"] = f"Expected compilation error, but it succeeded.\nOutput:\n{comp_res.stderr}\n{comp_res.stdout}".strip()
        else:
            result["passed"] = True

        if os.path.exists(obj_file): os.remove(obj_file)
        return result
