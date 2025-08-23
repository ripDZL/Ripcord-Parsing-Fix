# Ripcord-Parsing-Fix (WINDOWS ONLY)
Fixes Ripcord’s “Parsing: Invalid map key” error by patching specific bytes in the executable
A small Windows patcher for Ripcord.exe.  
It will backup the original file and patch specific bytes at fixed offsets.

## 🔧 Usage
1. Download the latest `patcher.exe` from the releases tab 
2. Place `patcher.exe` inside the **same folder** as `Ripcord.exe`.
3. Run `patcher.exe`.
4. Your original Ripcord.exe will be backed up inside a `backup/` folder.
5. You shouldnt now be able to connect discord again through ripcord.

## 🛠 Building from source
Download patcher.py and run "pyinstaller --onefile patcher.py" in the same directory. Should make a patcher.exe in a folder called dist in the same directory.
