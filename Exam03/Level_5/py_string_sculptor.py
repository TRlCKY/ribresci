def string_sculptor(text: str) -> str:
    x = len(text)
    n = 0
    new_text = ""
    if x == 0:
        return text

    i = 0
    while i < x:
        if text[i] == ' ':
            n = 0
        while (i < x and not text[i].isalpha()):
            new_text += text[i]
            i = i + 1
        while (i < x and text[i].isalpha()):
            if n % 2 == 0:
                new_text += text[i].lower()
            elif n % 2 == 1:
                new_text += text[i].upper()
            n = n + 1
            i = i + 1
    return new_text


def main():
    print(string_sculptor(""))


main()
