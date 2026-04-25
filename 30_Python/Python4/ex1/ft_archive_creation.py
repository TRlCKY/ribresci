import sys


def main():
    print("=== Cyber Archives Recovery ===")
    try:
        print(f"Usage: {sys.argv[0]}")
        if len(sys.argv) == 1:
            raise Exception("No files provided")
        elif len(sys.argv) == 2:
            file = sys.argv[1]
            print(f"TRYING TO OPEN FILE: '{file}'\n")
            f = open(file)
            print("FILE OPENED\n")
            print("FILE CONTENT:\n")
            print(f.read())
            old_file = f.readlines()
            f.close()
            print("TRANSFORMING DATA...")
            f = open(file, "w")
            for line in old_file:
                f.write(line)
                f.write("#\n")
            f.close()
            f = open(file)
            print(f.read())
            print("\nCLOSING FILE...")
            f.close()
            print("FILE CLOSED. END OF THE PROGRAM.")
        else:
            raise Exception("Too many files")
    except FileNotFoundError as e:
        print(f"File error: {e}")
    except PermissionError as e:
        print(f"Permission error: {e}")
    except Exception as e:
        print(f"Error: {e}")


if __name__ == "__main__":
    main()
