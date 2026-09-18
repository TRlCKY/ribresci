def string_permutation_checker(s1: str, s2: str) -> bool:
    x = len(s1)
    i = 0
    if x != len(s2):
        return False
    if x == 0:
        return True
    while i < x:
        if s1[i] not in s2:
            return False
        if count(s1, s1[i]) != count(s2, s1[i]):
            return False
        i = i + 1
    return True


def count(s0: str, c: str) -> int:
    x = len(s0)
    i = 0
    n = 0
    while (i < x):
        if s0[i] == c:
            n = n + 1
        i = i + 1
    return n


# def main():
#    print(string_permutation_checker("abc", "bca"))
# main()
