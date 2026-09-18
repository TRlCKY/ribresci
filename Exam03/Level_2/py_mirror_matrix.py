def mirror_matrix(matrix: list[list[int]]) -> list[list[int]]:
    i = 0
    e = 0
    n = 0
    while e < len(matrix):
        i = 0
        while i < (len(matrix[0]) / 2):
            n = matrix[e][i]
            matrix[e][i] = matrix[e][len(matrix[0]) - i - 1]
            matrix[e][len(matrix[0]) - i - 1] = n
            i = i + 1
        e = e + 1
    return matrix


# def main():
#     matrix = [[-1,-2],[-3,-4]]
#     print(matrix)
#     print(len(matrix))
#     print(len(matrix[0]))
#     print(mirror_matrix(matrix))


# main()
