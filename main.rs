use std::fs::{self, File};
use std::io::{self, Read, Write, Seek, SeekFrom};
use std::path::Path;

// Define offsets and bytes to patch (from patcher.py)
const OFFSETS: &[u64] = &[0xB8FBF, 0xB8FC0];
const PATCH_BYTES: &[u8] = &[0xEB, 0x80];

fn main() -> io::Result<()> {
    // Create backup directory
    let backup_dir = Path::new("backup");
    if !backup_dir.exists() {
        fs::create_dir(backup_dir)?;
        println!("Created backup directory");
    }

    // Backup Ripcord.exe
    let src_path = Path::new("Ripcord.exe");
    let backup_path = backup_dir.join("Ripcord.exe");
    if !src_path.exists() {
        eprintln!("Error: Ripcord.exe not found in current directory");
        return Err(io::Error::new(io::ErrorKind::NotFound, "Ripcord.exe not found"));
    }
    fs::copy(src_path, &backup_path)?;
    println!("Backup created at {}", backup_path.display());

    // Patch Ripcord.exe
    let mut file = File::options().read(true).write(true).open(src_path)?;
    for (&offset, &byte) in OFFSETS.iter().zip(PATCH_BYTES.iter()) {
        file.seek(SeekFrom::Start(offset))?;
        file.write_all(&[byte])?;
        println!("Patched byte 0x{:02x} at offset 0x{:x}", byte, offset);
    }

    println!("Patching complete. You can now use Ripcord.exe.");
    Ok(())
}