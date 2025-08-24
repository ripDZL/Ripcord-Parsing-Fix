![image alt](https://github.com/ripDZL/Ripcord-Parsing-Fix/blob/main/SCREENSHOT.JPG?raw=true)



#𝐅𝐎𝐔𝐍𝐃 𝐕𝐀𝐋𝐄𝐒 𝐁𝐘 𝐌𝐔𝐅𝐅𝐈𝐍𝐋𝐎𝐑𝐃 (𝐃𝐈𝐒𝐂𝐎𝐑𝐃)

#𝐂𝐎𝐃𝐄 𝐂𝐑𝐄𝐃𝐈𝐓:𝐆𝐑𝐎𝐊

#𝐈 𝐃𝐎𝐍𝐓 𝐂𝐎𝐃𝐄 𝐒𝐎 𝐈 𝐇𝐀𝐃 𝐆𝐑𝐎𝐊 𝐃𝐑𝐔𝐌 𝐔𝐏 𝐀 𝐑𝐔𝐒𝐓 𝐏𝐀𝐓𝐂𝐇


# Ripcord Parsing Fix (Windows Only)

This tool fixes the "Parsing: Invalid map key" error in Ripcord, a Discord client, by updating specific parts of the `Ripcord.exe` file. It automatically backs up your original `Ripcord.exe` before making changes, so your file is safe. Works on Windows 7 to Windows 11.

## 🔧 How to Use the Prebuilt Fix
If you just want to fix Ripcord without building anything, follow these simple steps:

1. Go to the [Releases page](https://github.com/ripDZL/Ripcord-Parsing-Fix/releases).
2. Click on the latest release (e.g., "Patcher v1.0.0").
3. Download the `patcher.exe` file.
4. Find your `Ripcord.exe` file (usually in the folder where Ripcord is installed).
5. Move `patcher.exe` to the same folder as `Ripcord.exe`.
6. Double-click `patcher.exe` to run it.
7. A `backup` folder will be created with a copy of your original `Ripcord.exe`.
8. Run Ripcord, and you should now be able to connect to Discord again.
9. Enjoy!

**Note**: If `patcher.exe` doesn’t work, ensure it’s in the same folder as `Ripcord.exe`. Contact me via GitHub if you need help.

## 🛠 Building the Fix Yourself
If you want to create `patcher.exe` from scratch (or the prebuilt version isn’t working), you can build it using a free tool called MinGW-w64. This works directly on Windows, including Windows 7 to 11, with no complex software needed. Don’t worry if you’re new—I’ll guide you step-by-step.

### What You Need
- A Windows computer (Windows 7 or later).
- An internet connection to download MinGW-w64.
- About 10 minutes to set up.

### Steps to Build
```bash
# 1. Download MinGW-w64:
#    - Visit https://winlibs.com/ in your web browser.
#    - Find the latest "UCRT" version (e.g., mingw-w64-gcc-13.2.0-llvm-18.1.8-mingw-w64ucrt-x86_64-7z).
#    - Download the ZIP file and unzip it to a folder you can find, like C:\MinGW-w64.
#    - You’ll see a mingw64 folder inside with a bin folder.

# 2. Add MinGW-w64 to your system:
#    - Right-click "This PC" (or "My Computer" on Windows 7) > Properties > Advanced system settings > Environment Variables.
#    - Find "Path" under "System variables," click Edit, and add:
C:\MinGW-w64\bin
#    - Adjust the path if you unzipped to a different folder (e.g., C:\MyFolder\bin).
#    - Click OK to save all changes.

# 3. Verify MinGW-w64:
#    - Open a Command Prompt (Windows Key + R, type "cmd", press Enter).
#    - Type:
gcc --version
#    - You should see a version number (e.g., gcc 13.2.0). If not, double-check the Path or re-unzip MinGW-w64.

# 4. Download the project files:
#    - Go to https://github.com/ripDZL/Ripcord-Parsing-Fix.
#    - Click the green "Code" button and select "Download ZIP".
#    - Unzip the folder to a place you can find (e.g., Desktop).
#    - Inside, you’ll see patcher.c.

# 5. Open a Command Prompt:
#    - Press Windows Key + R, type "cmd", and press Enter.

# 6. Navigate to the project folder:
#    - Type:
cd path\to\your\unzipped\folder
#    - Replace "path\to\your\unzipped\folder" with the folder’s location (e.g., cd C:\Users\YourName\Desktop\Ripcord-Parsing-Fix).

# 7. Build the patcher:
#    - Type:
gcc -o patcher.exe patcher.c
#    - Press Enter and wait (this should take a few seconds).

# 8. Find the patcher:
#    - Look in your project folder for patcher.exe.

# 9. Optional: Make the file smaller:
#    - Download UPX from https://upx.github.io/ (click "Downloads" and get the Windows version, e.g., upx-4.2.4-win64.zip).
#    - Unzip UPX and place upx.exe in the same folder as patcher.exe.
#    - In the Command Prompt, type:
upx --best patcher.exe
#    - This shrinks patcher.exe to save space.

# 10. Use the patcher:
#    - Move patcher.exe to the same folder as Ripcord.exe.
#    - Double-click patcher.exe to run it.
#    - Check that a backup folder with Ripcord.exe appears.
#    - Run Ripcord to confirm it connects to Discord.
