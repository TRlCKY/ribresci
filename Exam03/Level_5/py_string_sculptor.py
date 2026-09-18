def string_sculptor(text: str) -> str:
    x = len(text)
    n = 0
    if x == 0:
        return text

    i = 0
    while i < x:
        while i < x and text[i] <= "z" and text[i] >= "a" and text[i] <= "Z" and text[i] >= "A":
            i = i + 1
        n = 0
        while i < x and text[i] >= "a" and text[i] <= "z" or text[i] >= "A" and text[i] <= "Z":
            if n % 2 == 0 and text[i] >= "A" and text[i] <= "Z":
                # Conversione da maiuscola a minuscola
                print()
            elif n % 2 == 1 and text[i] >= "a" and text[i] <= "z":
                text[i] = text[i].capitalize()
            n = n + 1
            i = i + 1
    return text


def main():
    print(string_sculptor("hello"))


main()
