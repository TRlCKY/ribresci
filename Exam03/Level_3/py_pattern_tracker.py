def pattern_tracker(text: str) -> int:
    x = len(text) - 1
    i = 0
    n = 0
    while (i < x):
        if text[i] >= "0" and text[i] <= "9" and text[i + 1] >= "0" and text[i + 1] <= "9":
            if text[i] == "0" and text[i + 1] == "1" or text[i] == "1" and text[i + 1] == "2" or text[i] == "2" and text[i + 1] == "3" or text[i] == "3" and text[i + 1] == "4" or text[i] == "4" and text[i + 1] == "5" or text[i] == "5" and text[i + 1] == "6" or text[i] == "6" and text[i + 1] == "7" or text[i] == "7" and text[i + 1] == "8" or text[i] == "8" and text[i + 1] == "9":
                n = n + 1
        i = i + 1
    return n


def main():
    print(pattern_tracker("1a2b3c4"))


main()
