import os
import glob

# Get the directory of the script
script_dir = os.path.dirname(os.path.abspath(__file__))

# Define the file extensions to clean up
extensions = [
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
]

# Recursively find and delete each type of file
for ext in extensions:
    # Find all files matching the current extension in the script directory and subdirectories
    files = glob.glob(os.path.join(script_dir, '**', ext), recursive=True)
    
    # Check if files exist and delete them
    for file in files:
        try:
            os.remove(file)
            print(f"Deleted: {file}")
        except Exception as e:
            print(f"Could not delete: {file}. Error: {e}")

print("Cleanup complete.")
