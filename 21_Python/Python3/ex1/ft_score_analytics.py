import sys


def main():
    argv_len = len(sys.argv)
    print("=== Player Score Analytics ===")
    try:
        if argv_len == 1:
            raise Exception(f"No scores provided. Usage: {sys.argv[0]}")
        else:
            x = 0
            for i in range(argv_len):
                if i != 0:
                    lenght = len(sys.argv[i])
                    num = sys.argv[i]
                    for e in range(lenght):
                        if num[e] < '0' or num[e] > '9':
                            print(f"Invalid parameter: '{num}'")
                            x = 1
                            break
            if x == 1:
                raise Exception("No scores provided."
                                f" Usage: {sys.argv[0]}")
            array_lenght = len(sys.argv) - 1
            array = [0] * array_lenght
            avg = 0
            for i in range(array_lenght):
                array[i] = int(sys.argv[i + 1])
                avg += int(array[i])
            print(f"Scores processed: {array}")
            print(f"Total players: {len(array)}")
            print(f"Total score: {sum(array)}")
            print(f"Average score: {avg / array_lenght}")
            print(f"High score: {max(array)}")
            print(f"Low score: {min(array)}")
            print(f"Score range: {max(array) - min(array)}")
    except Exception as e:
        print(e)


if __name__ == "__main__":
    main()
