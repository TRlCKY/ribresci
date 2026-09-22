def twist_sequence(arr: list[int], k: int) -> list[int]:
    if len(arr) <= 1:
        return arr
    while k > 0:
        arr.insert(0, arr.pop())
        k = k - 1
    return arr

# def main():
#    arr = [1,2,3,4,5]
#    k = 2
#    print(twist_sequence([], 5))


# main()
