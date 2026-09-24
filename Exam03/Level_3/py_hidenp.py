def hidenp(small: str, big: str) -> bool:
    i = 0
    e = 0
    while i < len(big) and e < len(small):
        if small[e] == big[i]:
            e = e + 1
        i = i + 1
    if e == len(small):
        return True
    return False


def main():
    small = "sing"
    big = "subsequence testing"
    print(hidenp(small, big))


main()
