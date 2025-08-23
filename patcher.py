#!/usr/bin/env python3
import os, sys, json, shutil, datetime

# === Embedded patches.json data ===
PATCHES_JSON = {
    "verify": True,
    "patches": [
        {
            "offset": "0xB8FBF",
            "replace": "EB",
            "expect": None
        },
        {
            "offset": "0xB8FC0",
            "replace": "80",
            "expect": None
        }
    ]
}

def apply_patches(exe_path, patches):
    # Make backup folder
    backup_dir = os.path.join(os.path.dirname(exe_path), "backup")
    os.makedirs(backup_dir, exist_ok=True)

    # Copy exe to backup with timestamp
    ts = datetime.datetime.now().strftime("%Y%m%d_%H%M%S")
    backup_path = os.path.join(backup_dir, f"{os.path.basename(exe_path)}.{ts}.bak")
    shutil.copy2(exe_path, backup_path)
    print(f"[+] Backup created: {backup_path}")

    with open(exe_path, "rb+") as f:
        data = bytearray(f.read())

        for patch in patches["patches"]:
            offset = int(patch["offset"], 16)
            new_bytes = bytes.fromhex(patch["replace"])
            expect = bytes.fromhex(patch["expect"]) if patch["expect"] else None

            # Safety check
            if offset + len(new_bytes) > len(data):
                print(f"[-] Offset {hex(offset)} out of range.")
                return False

            old_bytes = data[offset:offset+len(new_bytes)]
            if expect and old_bytes != expect:
                print(f"[-] Mismatch at {hex(offset)}: expected {expect.hex()} got {old_bytes.hex()}")
                return False

            print(f"[+] Patching {hex(offset)}: {old_bytes.hex()} -> {new_bytes.hex()}")
            data[offset:offset+len(new_bytes)] = new_bytes

        # Write patched file
        f.seek(0)
        f.write(data)
    print("[+] Patching complete.")
    return True

def main():
    exe_path = "Ripcord.exe"
    if not os.path.exists(exe_path):
        print("[-] Ripcord.exe not found in this directory.")
        sys.exit(1)

    success = apply_patches(exe_path, PATCHES_JSON)
    sys.exit(0 if success else 1)

if __name__ == "__main__":
    main()
