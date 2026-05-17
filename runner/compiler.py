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
    def preprocess(self, source_file: str, output_file: str, pure: bool = False, standard: Optional[str] = None, timeout: int = 10) -> CompilationResult:
        """Runs the preprocessor only."""
        pass

    @abc.abstractmethod
    def compile(self, source_file: str, output_file: str, is_executable: bool = True, standard: Optional[str] = None, timeout: int = 10) -> CompilationResult:
        """Compiles the source file."""
        pass

    def _run_command(self, cmd: List[str], timeout: int = 10) -> CompilationResult:
        """Runs a command with a timeout."""
        try:
            result = subprocess.run(cmd, capture_output=True, text=True, timeout=timeout)
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

    def _get_std_flag(self, standard: Optional[str]) -> List[str]:
        std = (standard or "c11").lower()
        if self.name == "cendol":
            return ["--std", std]
        else:
            # GCC/Clang
            if std == "c23":
                # Use c2x as it is more widely supported across GCC 13/14 and Clang versions
                return ["-std=c2x"] 
            return [f"-std={std}"]

    def preprocess(self, source_file: str, output_file: str, pure: bool = False, standard: Optional[str] = None, timeout: int = 10) -> CompilationResult:
        cmd = [self.path, "-E"]
        if pure:
            cmd.append("-P")
            cmd.append("-I.")
        
        std_flag = self._get_std_flag(standard)
        cmd += self.extra_args + std_flag + [source_file, "-o", output_file]
        return self._run_command(cmd, timeout)

    def compile(self, source_file: str, output_file: str, is_executable: bool = True, standard: Optional[str] = None, timeout: int = 10) -> CompilationResult:
        std_flag = self._get_std_flag(standard)
        cmd = [self.path] + self.extra_args + std_flag + [source_file, "-o", output_file]
        if not is_executable:
            cmd.append("-c")
        
        result = self._run_command(cmd, timeout)
        if is_executable and result.success and os.path.exists(output_file):
            result.executable = output_file
        return result
