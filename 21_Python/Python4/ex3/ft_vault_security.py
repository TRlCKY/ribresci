def secure_archive(file: str, action: str,
                   new_content: str) -> tuple[bool, str]:
    try:
        if action == "r":
            print(f"Trying to open: '{file}'")
            with open(file) as f:
                return (True, f.read())
        elif action == "w":
            print(f"Trying to open: '{file}'")
            with open(file, action) as f:
                f.write(new_content)
                return (True, "Content successfully written to file")
        else:
            raise Exception("Invalid operation")
    except FileNotFoundError as e:
        return (False, f"[STDERR] Error opening file '{file}': {e}")
    except PermissionError as e:
        return (False, f"[STDERR] Permission denied to '{file}': {e}")
    except Exception as e:
        return (False, f"Error: {e}")


def main():
    print("=== Cyber Archives Security ===")
    print()
    print("Using 'secure_archive' to read from a nonexistent file:")
    tupleE = secure_archive("bobby.txt", "r", None)
    print(tupleE)
    print()
    print("Using 'secure_archive' to read from a inaccessible file:")
    tupleE = secure_archive("/etc/master.passwd", "r", None)
    print(tupleE)
    print()
    print("Using 'secure_archive' to read from a regular file:")
    tupleR = secure_archive("ciao.txt", "r", None)
    print(tupleR)
    print()
    print("Using 'secure_archive' to write from a regular file:")
    tupleW = secure_archive("ciao.txt", "w", "CiaoCiaoCiao")
    print(tupleW)
    print()


if __name__ == "__main__":
    main()
