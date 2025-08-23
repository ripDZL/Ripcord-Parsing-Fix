# Ripcord Parsing Fix (Windows Only)
Patches the "Parsing: Invalid map key" error in Ripcord by modifying specific bytes in the executable.

This tool creates a backup of the original `Ripcord.exe` file and applies patches at offsets `0xB8FBF` and `0xB8FC0`.

## 🔧 Usage
1. Download the latest `patcher.exe` from the [Releases](https://github.com/ripDZL/Ripcord-Parsing-Fix/releases) tab.
2. Place `patcher.exe` in the **same folder** as `Ripcord.exe`.
3. Run `patcher.exe`.
4. The original `Ripcord.exe` will be backed up in a `backup/` folder.
5. You should now be able to connect to Discord via Ripcord again.
6. Enjoy using Ripcord!

## 🛠 Building from Source
The patcher is written in Rust, producing a small, efficient executable. Follow these steps to build it yourself.

### Requirements
- [Rust](https://rustup.rs/) (install via `rustup-init.exe` for Windows).

### Steps
```bash
# 1. Download src/main.rs from the repository (https://github.com/ripDZL/Ripcord-Parsing-Fix).
# 2. Create a new Rust project:
cargo init --bin
# 3. Replace src/main.rs with the downloaded file.
# 4. Build the executable in release mode for a smaller binary:
cargo build --release
# 5. Find patcher.exe in target/release/ (rename from ripcord-patcher.exe if desired).
# 6. Optional: Minimize the executable size by adding the following to Cargo.toml before building:
cat <<EOT >> Cargo.toml
[profile.release]
opt-level = 'z'  # Optimize for size
lto = true       # Enable link-time optimization
codegen-units = 1
panic = 'abort'  # Remove panic handling code
strip = true     # Strip symbols
EOT
# 7. Rebuild with cargo build --release.
# 8. Optional: Install UPX (https://upx.github.io/) and run:
upx --best target/release/patcher.exe
# 9. Place patcher.exe in the same folder as Ripcord.exe and run it.
