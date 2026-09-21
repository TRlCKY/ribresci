def string_sculptor(text: str) -> str:
    x = len(text)
    n = 0
    new_text = ""
    if x == 0:
        return text

    i = 0
    while i < x:
        while (i < x and text[i] <= "a" and text[i] >= "z"
               and text[i] <= "A" and text[i] >= "Z"):
            new_text += text[i]
            i = i + 1
        n = 0
        while (i < x and text[i] >= "a" and text[i] <= "z" or text[i] >= "A"
               and text[i] <= "Z"):
            if n % 2 == 0 and text[i] >= "A" and text[i] <= "Z":
                new_text += text[i].lower()
            elif n % 2 == 1 and text[i] >= "a" and text[i] <= "z":
                new_text += text[i].upper()
            n = n + 1
            i = i + 1
    return new_text


def main():
    print(string_sculptor("hello"))


main()
