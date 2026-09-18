def number_base_converter(number: str, from_base: int, to_base: int) -> str:
    if from_base < 2 or from_base > 36:
        return "ERROR"
    abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    i = 0
    while i < len(number):
        if (from_base <= 10 and number[i] in abc):
            return "ERROR"
        i = i + 1
    return number


def main():
    number = '1010'
    from_base = 2
    to_base = 10
    print(number_base_converter(number, from_base, to_base))


main()
