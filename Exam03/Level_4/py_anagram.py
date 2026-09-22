def anagram(s1: str, s2: str) -> bool:
    if len(s1) == 0 and len(s2) == 0:
        return True
    s1 = sorted(s1)
    s2 = sorted(s2)
    i = 0
    e = 0
    while i < len(s1):
        if not (s1[i] >= "a" and s1[i] <= "z" or
                            s1[i] >= "A" and s1[i] <= "Z"):
            s1.pop(i)
        else:
            i = i + 1
    i = 0
    while i < len(s2):
            if not (s2[i] >= "a" and s2[i] <= "z" or
                                s2[i] >= "A" and s2[i] <= "Z"):
                s2.pop(i)
            else:
                i = i + 1
    i = 0
    if len(s1) != len(s2):
        return False
    while i < len(s1):
        e = 0
        x = 0
        while e < len(s2):
            if s1[i] == s2[e] or ord(s1[i]) == ord(s2[e]) - 32 or ord(s1[i]) == ord(s2[e]) + 32:
                x = x + 1
            e = e + 1
        if x == 0:
            return False
        i = i + 1
    return True


def main():
    s1 = "abc"
    s2 = "abcc"
    print(anagram(s1, s2))


main()