# Run with:
# python3 -m mypy --strict typecheck.py

from typing import List, Dict, MutableMapping

def foo(bar: Dict[str, int]) -> int:
    return 1

a: Dict[str, int] = {}
b: str = foo(a)