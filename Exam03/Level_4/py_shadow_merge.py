def shadow_merge(list1: list[int], list2: list[int]) -> list[int]:
    list1.extend(list2)
    list1.sort()
    return list1


# def main():
#     list1 = [1, 5]
#     list2 = [2, 4, 6]
#     print(shadow_merge(list1, list2))


# main()
