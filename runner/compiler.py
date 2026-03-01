import abc
import subprocess
import re
import os
from dataclasses import dataclass
from typing import Optional, List

@dataclass
class CompilationResult:
    success: bool
    returncode: int
    stdout: str
    stderr: str
    executable: Optional[str] = None

class CompilerAdapter(abc.ABC):
    @abc.abstractmethod
    def get_name(self) -> str:
        """Returns the name of the compiler."""
        pass

    @abc.abstractmethod
    def preprocess(self, source_file: str, output_file: str, pure: bool = False) -> CompilationResult:
        """Runs the preprocessor only."""
        pass

    @abc.abstractmethod
    def compile(self, source_file: str, output_file: str, is_executable: bool = True) -> CompilationResult:
        """Compiles the source file."""
        pass

    def run(self, executable: str) -> CompilationResult:
        """Runs the compiled executable."""
        try:
            result = subprocess.run([executable], capture_output=True, text=True, timeout=5)
            return CompilationResult(
                success=(result.returncode == 0),
                returncode=result.returncode,
                stdout=result.stdout,
                stderr=result.stderr
            )
        except subprocess.TimeoutExpired:
            return CompilationResult(success=False, returncode=-1, stdout="", stderr="Timeout expired")
        except Exception as e:
            return CompilationResult(success=False, returncode=-1, stdout="", stderr=str(e))

    def match_diagnostic(self, stderr: str, pattern: str) -> bool:
        """Matches a regex pattern in the compiler diagnostics."""
        return re.search(pattern, stderr, re.IGNORECASE) is not None

class GccLikeAdapter(CompilerAdapter):
    """
    Base class for compilers that follow the GCC/Clang command-line interface.
    """
    def __init__(self, name: str, path: str, extra_args: List[str] = None):
        self.name = name
        self.path = os.path.expanduser(path)
        self.extra_args = [os.path.expanduser(arg) for arg in (extra_args or [])]

    def get_name(self) -> str:
        return self.name

    def preprocess(self, source_file: str, output_file: str, pure: bool = False) -> CompilationResult:
        cmd = [self.path, "-E"]
        if pure:
            cmd.append("-P")
        cmd += self.extra_args + [source_file, "-o", output_file]
        result = subprocess.run(cmd, capture_output=True, text=True)
        return CompilationResult(
            success=(result.returncode == 0),
            returncode=result.returncode,
            stdout=result.stdout,
            stderr=result.stderr
        )

    def compile(self, source_file: str, output_file: str, is_executable: bool = True) -> CompilationResult:
        cmd = [self.path] + self.extra_args + [source_file, "-o", output_file]
        if not is_executable:
            cmd.append("-c")
        
        result = subprocess.run(cmd, capture_output=True, text=True)
        return CompilationResult(
            success=(result.returncode == 0),
            returncode=result.returncode,
            stdout=result.stdout,
            stderr=result.stderr,
            executable=output_file if is_executable and result.returncode == 0 and os.path.exists(output_file) else None
        )
