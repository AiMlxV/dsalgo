import os
import re

def rename_files():
    # --- CONFIGURATION ---
    # Set this to False to actually rename the files.
    # Keep it True to see a preview of changes first.
    DRY_RUN = False 
    # ---------------------

    # Get the current working directory
    current_dir = os.getcwd()
    
    # Regex Explanation:
    # ^          : Start of the string
    # (\d{1,2})  : Group 1 - The Date (1 or 2 digits)
    # -          : A literal hyphen
    # ([A-Za-z]+): Group 2 - The Month (Letters like Nov, Dec)
    # (.*)       : Group 3 - The rest of the filename (e.g., __Title)
    # $          : End of string
    pattern = re.compile(r"^(\d{1,2})-([A-Za-z]+)(.*)$")

    print(f"Scanning directory: {current_dir}")
    print(f"Mode: {'DRY RUN (No changes will be made)' if DRY_RUN else 'LIVE (Renaming files)'}")
    print("-" * 50)

    count = 0

    for filename in os.listdir(current_dir):
        # Apply regex to find files matching "Date-Month..."
        match = pattern.match(filename)
        
        if match:
            day = match.group(1)
            month = match.group(2)
            rest = match.group(3)

            # Construct the new name: Month-Day + rest
            new_name = f"{month}-{day}{rest}"

            # Skip if the name is already in the correct format (unlikely given the regex, but good practice)
            if new_name == filename:
                continue

            # Check if destination already exists to prevent overwriting
            if os.path.exists(new_name) and not DRY_RUN:
                print(f"[SKIP] Target exists: {filename} -> {new_name}")
                continue

            # Perform the rename or print the plan
            if DRY_RUN:
                print(f"[PREVIEW] Would rename: '{filename}' -> '{new_name}'")
            else:
                try:
                    os.rename(filename, new_name)
                    print(f"[SUCCESS] Renamed: '{filename}' -> '{new_name}'")
                except OSError as e:
                    print(f"[ERROR] Could not rename '{filename}': {e}")
            
            count += 1

    print("-" * 50)
    if count == 0:
        print("No matching files found to rename.")
    else:
        print(f"Processed {count} files.")

if __name__ == "__main__":
    rename_files()
