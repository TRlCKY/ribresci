def hidenp(small: str, big: str) -> bool:
    x = 0
    i = 0
    e = 0
    while i < len(big):
        e = 0
        while e < len(small):
            if small[e] == big[i]:
                x = x + 1
                break
            e = e + 1
        i = i + 1
    if x >= len(small):
        return True
    return False


# def main():
#     small = "sing"
#     big = "subsequence testing"
#     print(hidenp(small, big))


# main()
