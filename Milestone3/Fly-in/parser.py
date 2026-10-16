import sys


class parsingException(Exception):
    pass


def parser(argv: list[str]) -> int:
    with open(argv[1], "r") as f:
        text = f.read()
    x = 0
    line0 = text.realine()
    while x == 0 and line0 != "\0":
        if line0.startswith("#") and line0.startswith("nb_drones: "):
            x = 1
        line0 = text.realine()
    while text:
        line = text.readline()


def main():
    argv = sys.argv
    if parser(argv) == 0:
        print()
    print()


if __name__ == "__main__":
    main()
