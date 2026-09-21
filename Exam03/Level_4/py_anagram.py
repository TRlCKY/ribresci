def anagram(s1: str, s2: str) -> bool:
    if sorted(s1) == sorted(s2):
        return True
    return False


def main():
    s1 = "triangle"
    s2 = "inteqral"
    print(anagram(s1, s2))


main()
