# Get the directory of the script
$scriptDir = $PSScriptRoot

# Define the file extensions to clean up
$extensions = @(
    "*.o",        # Object files (Linux/Unix)
    "*.obj",      # Object files (Windows)
    "*.exe",      # Executable files (Windows)
    "*.out",      # Executable files (Linux/Unix)
    "*.log",      # Log files
    "*.pdb",      # Program database files (Windows)
    "*.ilk",      # Incremental linker files (Windows)
    "*.sln",      # Solution files (Visual Studio)
    "*.vcxproj",  # Visual Studio project files
    "*.vcxproj.user", # Visual Studio user-specific settings
    "*.tmp",      # Temporary files
    "*.dSYM",     # Debug symbol files (macOS)
    "*.make",     # Make files
    "*.cmake",    # CMake files
    "*.cache",    # Cache files
    "*.a",        # Archive files (Linux/Unix static libraries)
    "*.lib",      # Static library files (Windows)
    "*.dll"       # Dynamic library files (Windows)
)

# Recursively find and delete each type of file
foreach ($ext in $extensions) {
    # Find all files matching the current extension in the script directory and subdirectories
    $files = Get-ChildItem -Path $scriptDir -Filter $ext -Recurse -File -ErrorAction SilentlyContinue

    # Check if files exist and delete them
    foreach ($file in $files) {
        try {
            Remove-Item -Path $file.FullName -Force
            Write-Host "Deleted: $($file.FullName)"
        }
        catch {
            Write-Warning "Could not delete: $($file.FullName)"
        }
    }
}

Write-Host "Cleanup complete."
