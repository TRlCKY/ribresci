import sys


def main():
    print("=== Cyber Archives Recovery & Preservation===")
    try:
        print(f"Usage: {sys.argv[0]}")
        if len(sys.argv) == 1:
            raise Exception("No files provided")
        elif len(sys.argv) == 2:
            file = sys.argv[1]
            print(f"Trying to open: '{file}'")
            print()
            with open(file) as f:
                print("File opened")
                print("File content:")
                content = f.read()
                print(f"{content}\n")
            with open(file) as f:
                old_file = list()
                old_file = f.readlines()
            print("Transforming data...")
            with open(file, "w") as f:
                f.write("")
            with open(file, "a") as f:
                for line in old_file:
                    line1 = line.split('\n')
                    f.write(line1[0])
                    f.write("#\n")
            with open(file) as f:
                print(f.read())
            new_name = input("Enter the new file name: ")
            if new_name == "\n":
                print("Not saving data")
            else:
                print(f"Saving data in file '{new_name}'")
                with open(new_name, "x") as n:
                    with open(file) as f:
                        copy_file = list()
                        copy_file = f.readlines()
                        for line in copy_file:
                            n.write(line)
                print(f"Data saved in {new_name}")
            print("\nClosing file...")
            print("File closed, end of the program.")
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
