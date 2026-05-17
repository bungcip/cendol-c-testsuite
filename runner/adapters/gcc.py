from runner.compiler import GccLikeAdapter

class GCCAdapter(GccLikeAdapter):
    def __init__(self):
        super().__init__("gcc", "gcc", ["-pedantic-errors"])
