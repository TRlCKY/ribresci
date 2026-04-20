import sys


def main():
    print("=== Command Quest ===")
    i = 0
    x = len(sys.argv)
    print(f"Program name: {sys.argv[i]}")
    if x >= 2:
        for i in range(x):
            if i != 0:
                print(f"Argument {i}: {sys.argv[i]}")
    else:
        print("No arguments provided!")
    print(f"Total arguments: {x}")


if __name__ == "__main__":
    main()
