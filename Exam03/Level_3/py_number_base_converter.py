def number_base_converter(number: str, from_base: int, to_base: int) -> str:
    if from_base < 2 or from_base > 36 or to_base < 2 or to_base > 36:
        return "ERROR"
    num_abc = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    new_number = ""
    if from_base != 10:
        number = convert(from_base, number)
    num_int = int(number)
    while num_int != 0:
        module = num_int % to_base
        num_int //= 10
        new_number.insert(0, num_abc[module])
    return new_number


def convert(from_base: int, number: str):
    number0 = []
    number10 = 0
    i = 0
    for n in number:
        if n.isalpha():
            number0.append((ord[n] - ord('A') + 10) * pow(from_base, len(number) - i - 1))
        else:
            number0.append((ord[n] - ord('0')) * pow(from_base, len(number) - i - 1))
        i += 1
    i = 0
    for i in range(len(number0)):
        number10 += int(number0[i])
    return str(number10)


def main():
    number = '10'
    from_base = 2
    to_base = 10
    print(number_base_converter(number, from_base, to_base))


main()
