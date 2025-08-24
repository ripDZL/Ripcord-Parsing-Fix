#include <stdio.h>
#include <stdlib.h>
#include <direct.h> // For _mkdir on Windows

// Patch offsets and bytes 
const long OFFSETS[] = {0xB8FBF, 0xB8FC0};
const unsigned char PATCH_BYTES[] = {0xEB, 0x80};
const int PATCH_COUNT = 2;

int main() {
    // Create backup directory
    if (_mkdir("backup") != 0) {
        printf("Note: Backup directory already exists or could not be created.\n");
    }

    // Verify Ripcord.exe exists
    FILE *src = fopen("Ripcord.exe", "rb");
    if (!src) {
        printf("Error: Could not find Ripcord.exe. Ensure it's in the same folder.\n");
        return 1;
    }

    // Verify file is large enough for patching
    fseek(src, 0, SEEK_END);
    long file_size = ftell(src);
    if (file_size < OFFSETS[PATCH_COUNT - 1] + 1) {
        printf("Error: Ripcord.exe is too small or invalid.\n");
        fclose(src);
        return 1;
    }
    rewind(src);

    // Backup Ripcord.exe
    FILE *backup = fopen("backup\\Ripcord.exe", "wb");
    if (!backup) {
        printf("Error: Could not create backup file.\n");
        fclose(src);
        return 1;
    }

    // Copy file to backup
    char buffer[4096];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        if (fwrite(buffer, 1, bytes, backup) != bytes) {
            printf("Error: Failed to write backup file.\n");
            fclose(src);
            fclose(backup);
            return 1;
        }
    }
    fclose(src);
    fclose(backup);
    printf("Backup created at backup\\Ripcord.exe\n");

    // Patch Ripcord.exe
    FILE *file = fopen("Ripcord.exe", "r+b");
    if (!file) {
        printf("Error: Could not open Ripcord.exe for patching.\n");
        return 1;
    }

    // Apply patches
    for (int i = 0; i < PATCH_COUNT; i++) {
        if (fseek(file, OFFSETS[i], SEEK_SET) != 0) {
            printf("Error: Could not seek to offset 0x%lx.\n", OFFSETS[i]);
            fclose(file);
            return 1;
        }
        if (fwrite(&PATCH_BYTES[i], 1, 1, file) != 1) {
            printf("Error: Could not write byte 0x%02x at offset 0x%lx.\n", PATCH_BYTES[i], OFFSETS[i]);
            fclose(file);
            return 1;
        }
        printf("Patched byte 0x%02x at offset 0x%lx\n", PATCH_BYTES[i], OFFSETS[i]);
    }

    fclose(file);
    printf("Patching complete. You can now use Ripcord.exe.\n");
    return 0;

}
