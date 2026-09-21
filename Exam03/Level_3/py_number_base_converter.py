def number_base_converter(number: str, from_base: int, to_base: int) -> str:
    if from_base < 2 or from_base > 36:
        return "ERROR"
    number0 = 0
    new_number0 = ""
    new_number = ""
    num_abc = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    for i in range(len(number)):
        if (number[i] >= num_abc[from_base]):
            return "ERROR"
    if from_base == to_base:
        return number
    elif from_base > to_base:
        x = int(number)
        while x >= 1:
            new_x = int(x % to_base)
            x = x / to_base
            new_number0 += num_abc[new_x]
        for i in range(len(new_number0)):
            new_number += new_number0[len(new_number0) - 1 - i]
    else:
        for i in range(len(number)):
            x = int(number[i]) * pow(to_base, i)
            number0 += x
            new_number +=
    return new_number


def main():
    number = '10'
    from_base = 2
    to_base = 10
    print(number_base_converter(number, from_base, to_base))


main()
