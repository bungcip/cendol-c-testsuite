import argparse
import sys
import os

# Add the project root to sys.path to allow importing from runner
sys.path.append(os.path.abspath(os.path.join(os.path.dirname(__file__), '..')))

from runner.adapters.gcc import GCCAdapter
from runner.adapters.clang import ClangAdapter
from runner.adapters.cendol import CendolAdapter
from runner.engine import TestEngine

def main():
    parser = argparse.ArgumentParser(description="C Conformance Test Runner")
    parser.add_argument("compiler", choices=["gcc", "clang", "cendol"], help="Compiler to test")
    parser.add_argument("--test-dir", default="tests", help="Directory containing tests")
    parser.add_argument("--test-num", help="Run specific test number (e.g. 00101)")
    parser.add_argument("--pattern", help="Run only tests matching this substring in their name")
    parser.add_argument("--category", choices=["preprocessor", "positive", "negative"], help="Run only tests in this category")
    parser.add_argument("--fail-fast", action="store_true", help="Stop on first failure")
    args = parser.parse_args()

    # ANSI Color codes
    GREEN = "\033[92m"
    RED = "\033[91m"
    RESET = "\033[0m"
    BOLD = "\033[1m"

    if args.compiler == "gcc":
        compiler = GCCAdapter()
    elif args.compiler == "clang":
        compiler = ClangAdapter()
    elif args.compiler == "cendol":
        compiler = CendolAdapter()
    else:
        print(f"Unsupported compiler: {args.compiler}")
        sys.exit(1)

    engine = TestEngine(compiler)
    
    # Preliminary Sanity Checks
    print(f"{BOLD}Step 1/2: Preliminary Sanity Checks...{RESET}", end=" ", flush=True)
    try:
        engine.verify_compiler_integrity()
        print(f"{GREEN}Passed{RESET}")
    except Exception as e:
        print(f"{RED}FAILED{RESET}")
        print(f"\n{BOLD}{RED}INTEGRITY ERROR: The compiler failed preliminary sanity tests.{RESET}")
        print(f"Details: {str(e)}")
        sys.exit(1)

    tests = engine.discover_tests(args.test_dir)

    # Filtering
    if args.test_num:
        padded_num = args.test_num.zfill(5)
        tests = [t for t in tests if os.path.basename(t.file_path).startswith(padded_num) or 
                                     os.path.basename(t.file_path).startswith(args.test_num)]
    if args.pattern:
        tests = [t for t in tests if args.pattern in t.name or args.pattern in os.path.basename(t.file_path)]
    if args.category:
        tests = [t for t in tests if t.category == args.category]

    if not tests:
        print(f"{RED}No tests found matching your criteria.{RESET}")
        sys.exit(0)

    print(f"\n{BOLD}Step 2/2: Running {len(tests)} tests with {compiler.get_name()}...{RESET}")
    print("-" * 60)

    passed_count = 0
    failed = False
    for test in tests:
        result = engine.run_test(test)
        if result["passed"]:
            status = f"{GREEN}PASS{RESET}"
            passed_count += 1
        else:
            status = f"{RED}FAIL{RESET}"
            failed = True
        
        print(f"[{status}] {test.name} ({result['file']})")
        if not result["passed"]:
            lines = result["message"].splitlines()
            if lines:
                print(f"       {RED}Reason: {lines[0]}{RESET}")
                for line in lines[1:]:
                    print(f"               {RED}{line}{RESET}")
            
            if args.fail_fast:
                print(f"\n{BOLD}{RED}Fail-fast enabled. Stopping on first error.{RESET}")
                break

    print("-" * 60)
    summary_color = GREEN if passed_count == len(tests) and not failed else RED
    print(f"{BOLD}Summary: {summary_color}{passed_count}/{len(tests)} tests passed{RESET}")
    
    if failed:
        sys.exit(1)

if __name__ == "__main__":
    main()
