from runner.compiler import GccLikeAdapter

class CendolAdapter(GccLikeAdapter):
    def __init__(self):
        super().__init__(
            name="cendol",
            path="~/cendol/target/debug/cendol",
            extra_args=["--std", "c11", "-I", "~/cendol/custom-include", "--pedantic-errors"]
        )
