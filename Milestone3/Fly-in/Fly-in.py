import sys
from parser import parser, init_hubs, get_values, parsingException


def start() -> None:
    argv = sys.argv
    try:
        list0 = get_values(argv)
        if parser(list0, argv[1]) == 0:
            init_hubs(list0)
    except parsingException as e:
        print(f"Got parsing Exception: {e}")
    except Exception as e:
        print(f"Got Exception: {e}")


if __name__ == "__main__":
    start()
