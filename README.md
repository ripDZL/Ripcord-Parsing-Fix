# Ripcord Parsing Fix (Windows Only)

This tool fixes the "Parsing: Invalid map key" error in Ripcord, a Discord client, by updating specific parts of the `Ripcord.exe` file. It automatically backs up your original `Ripcord.exe` before making changes, so your file is safe.

## 🔧 How to Use the Prebuilt Fix
If you just want to fix Ripcord without building anything, follow these simple steps:

1. Go to the [Releases page](https://github.com/ripDZL/Ripcord-Parsing-Fix/releases).
2. Click on the latest release
3. Download the `patcher.exe` file.
4. Find your `Ripcord.exe` file (usually in the folder where Ripcord is installed).
5. Move `patcher.exe` to the same folder as `Ripcord.exe`.
6. Double-click `patcher.exe` to run it.
7. A `backup` folder will be created with a copy of your original `Ripcord.exe`.
8. Run Ripcord, and you should now be able to connect to Discord again.
9. Enjoy!

## 🛠 Building the Fix Yourself
If you want to create `patcher.exe` from scratch (or the prebuilt version isn’t working), you can build it using Rust, a programming tool. Don’t worry if you’re new to this—I’ll guide you step-by-step. This creates the same `patcher.exe` as the prebuilt version.

### What You Need
- A Windows computer.
- An internet connection to download Rust.
- About 10-15 minutes to set up.

### Steps to Build
```bash
# 1. Install Rust:
#    - Visit https://rustup.rs/ in your web browser.
#    - Download and run rustup-init.exe.
#    - Press Enter to accept the default installation when prompted.
#    - Wait for Rust to install (it may take a few minutes).

# 2. Download the project files:
#    - Go to https://github.com/ripDZL/Ripcord-Parsing-Fix.
#    - Click the green "Code" button and select "Download ZIP".
#    - Unzip the folder to a place you can find (e.g., Desktop).
#    - Inside, you’ll see src/main.rs and Cargo.toml.

# 3. Open a Command Prompt:
#    - Press Windows Key + R, type "cmd", and press Enter.

# 4. Navigate to the project folder:
#    - In the Command Prompt, type:
cd path\to\your\unzipped\folder
#    - Replace "path\to\your\unzipped\folder" with the folder’s location (e.g., cd C:\Users\YourName\Desktop\Ripcord-Parsing-Fix).

# 5. Build the patcher:
#    - Type:
cargo build --release
#    - Press Enter and wait (this may take a minute or two).

# 6. Find the patcher:
#    - Go to the target/release folder inside your project folder.
#    - Look for patcher.exe.
#    - Rename it to patcher.exe (right-click, select "Rename").

# 7. Optional: Make the file smaller:
#    - Download UPX from https://upx.github.io/ (click "Downloads" and get the Windows version).
#    - Unzip UPX and place upx.exe in the target/release folder.
#    - In the Command Prompt, navigate to target/release:
cd target\release
#    - Type:
upx --best patcher.exe
#    - This shrinks patcher.exe to save space.

# 8. Use the patcher:
#    - Move patcher.exe to the same folder as Ripcord.exe.
#    - Double-click patcher.exe to run it.
#    - Check that a backup folder with Ripcord.exe appears.
#    - Run Ripcord to confirm it connects to Discord.
