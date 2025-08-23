# Ripcord-Parsing-Fix (WINDOWS ONLY)
Fixes Ripcord’s “Parsing: Invalid map key” error by patching specific bytes in the executable


It will backup the original file and patch specific bytes at fixed offsets.

## 🔧 Usage
1. Download the latest `patcher.exe` from the releases tab 
2. Place `patcher.exe` inside the **same folder** as `Ripcord.exe`.
3. Run `patcher.exe`.
4. Your original Ripcord.exe will be backed up inside a `backup/` folder.
5. You shouldnt now be able to connect discord again through ripcord.
6. Enjoy Ripcord once again!

## 🛠 Building from source
You can download the patcher.py and place inside the **same folder** as `Ripcord.exe and run patcher.py  to get the same result if you have python installed
OR Build a EXE VIA PPYINSTALLER (Requirements: ppyinstaller)
install via powershell via:  pip install pyinstaller 

Download patcher.py  and run "pyinstaller --onefile patcher.py" from a command prompt window in the same directory. Should make a patcher.exe in a folder called dist in the same directory.
