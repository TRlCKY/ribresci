def echo_validator(text: str) -> bool:
    x = len(text)
    if x == 0:
        return False

    i = 0
    e = x - 1
    while i < x:
        while text[i] == " " and i < x:
            i = i + 1
        while text[e] == " " and e > -1:
            e = e - 1
        if text[i].capitalize() != text[e].capitalize():
            return False
        i = i + 1
        e = e - 1

    return True


def main():
    print(echo_validator("abba"))


main()
