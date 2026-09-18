def cryptic_sorter(strings: list[str]) -> list[str]:
    if len(strings) <= 1:
        return strings
    # Dalla più corta alla più lunga
    string0 = ""
    x = 0
    while x < len(strings):
        i = 0
        while i < len(strings) - 1:
            if len(strings[i]) > len(strings[i + 1]):
                string0 = strings[i]
                strings[i] = strings[i + 1]
                strings[i + 1] = string0
            i = i + 1
        x = x + 1

    print("Stringa 1:")
    print(strings)
    # Valore ASCII (non per le lettere maiuscole/minuscole con la stessa lunghezza)
    x = 0
    while x < len(strings):
        i = 0
        while i < len(strings) - 1:
            e = 0
            if len(strings[i]) == len(strings[i + 1]):
                while e < len(strings[i]):
                    if (strings[i][e]).capitalize() > (strings[i + 1][e]).capitalize():
                        string0 = strings[i]
                        strings[i] = strings[i + 1]
                        strings[i + 1] = string0
                        break
                    elif (strings[i][e]).capitalize() == (strings[i + 1][e]).capitalize():
                        e = e + 1
                    elif (strings[i][e]).capitalize() < (strings[i + 1][e]).capitalize():
                        break
            i = i + 1
        x = x + 1

    return strings
    # Dal numero di vocali
    # Le stringhe uguali appaiono nello stesso ordine della lista di input


def main():
    strings = ['albz', 'c3d4', 'e5f6', 'g7h8']
    print(strings)
    print(cryptic_sorter(strings))

# main()
