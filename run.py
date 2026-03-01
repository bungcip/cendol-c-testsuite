#!/usr/bin/env python3
import subprocess
import sys
import os

def main():
    script_path = os.path.join(os.path.dirname(__file__), 'scripts', 'test.py')
    cmd = [sys.executable, script_path] + sys.argv[1:]
    try:
        result = subprocess.run(cmd)
        sys.exit(result.returncode)
    except KeyboardInterrupt:
        sys.exit(1)

if __name__ == "__main__":
    main()
