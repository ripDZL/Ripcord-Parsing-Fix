# Ripcord Parsing Fix (Windows Only)
Patches the "Parsing: Invalid map key" error in Ripcord by modifying specific bytes in the executable.

This tool creates a backup of the original `Ripcord.exe` file and applies the patch at fixed offsets.

## 🔧 Usage
1. Download the latest `patcher.exe` from the [Releases](https://github.com/ripDZL/Ripcord-Parsing-Fix/releases) tab.
2. Place `patcher.exe` in the **same folder** as `Ripcord.exe`.
3. Run `patcher.exe`.
4. The original `Ripcord.exe` will be backed up in a `backup/` folder.
5. You should now be able to connect to Discord via Ripcord again.
6. Enjoy using Ripcord!

## 🛠 Building from Source
You can achieve the same result as `patcher.exe` by running the Python script directly or building your own executable.

### Option 1: Run the Python Script
- Download `patcher.py` and place it in the **same folder** as `Ripcord.exe`.
- Ensure Python is installed.
- Run `patcher.py` from the command line or double click patcher.py to run patcher

### Option 2: Build the Executable
- **Requirements**: `pyinstaller` (install via PowerShell with `pip install pyinstaller`).
- Download `patcher.py`.
- Open a command prompt in the same directory as `patcher.py`.
- Run `pyinstaller --onefile patcher.py`.
- Find the generated `patcher.exe` in the `dist/` folder.
