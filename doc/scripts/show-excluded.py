"""List source files not actively imported into the reference document."""
import re
from pathlib import Path

root = Path("content")
imports = set()
for tex in root.rglob("*.tex"):
    for line in tex.read_text().splitlines():
        line = line.split("%", 1)[0]
        imports.update(re.findall(r"\\kactlimport(?:\[[^]]*\])?\{([^}]+)\}", line))
for source in sorted(root.rglob("*")):
    if source.suffix in {".h", ".py", ".java"} and source.name not in imports:
        print(source)
