from runner.compiler import GccLikeAdapter

class ClangAdapter(GccLikeAdapter):
    def __init__(self):
        super().__init__("clang", "clang", ["-std=c11", "-pedantic-errors"])
