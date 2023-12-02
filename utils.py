from pathlib import Path

def get_project_root() -> Path:
    return Path(__file__).parent

def get_module_path():
    root = get_project_root()
    return str(root / "build" / "Debug")