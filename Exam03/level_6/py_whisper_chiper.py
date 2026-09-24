def whisper_cipher(text: str, shift: int) -> str:
    if len(text) == 0 or shift == 0:
        return text
    new_text = ""
    i = 0
    for i in range(len(text)):
        if text[i].isalpha():
            new_char = ord(text[i])
            new_char += shift
            new_shift = 0
            if not chr(new_char).isalpha():
                if shift > 0:
                    while not chr(new_char).isalpha():
                        new_char -= 1
                        new_shift += 1
                    if text[i].islower():
                        new_char = ord('a') + new_shift - 1
                    else:
                        new_char = ord('A') + new_shift - 1
                else:
                    while not chr(new_char).isalpha():
                        new_char += 1
                        new_shift -= 1
                    if text[i].islower():
                        new_char = ord('z') + new_shift + 1
                    else:
                        new_char = ord('Z') + new_shift + 1
            new_text += chr(new_char)
        else:
            new_text += text[i]
        i = i + 1
    return new_text


def main():
    print(whisper_cipher("abc", -3))


main()
