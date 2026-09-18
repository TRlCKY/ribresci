def inter(s1: str, s2: str) -> str:
    s3 = ""
    i = 0
    e = 0
    while i < len(s1):
        e = 0
        while e < len(s2):
            if s1[i] == s2[e] and s1[i] not in s3:
                s3 = s3 + s1[i]
            e = e + 1
        i = i + 1
    return s3


# def main():
#     s1 = ""
#     s2 = "xyz"
#     print(inter(s1, s2))


# main()
