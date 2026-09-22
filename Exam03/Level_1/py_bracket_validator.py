def bracket_validator(s: str) -> bool:
    if len(s) == 0:
        return True
    i = 0
    array = []
    while i < len(s):
        if (s[i] == '(' or s[i] == '[' or s[i] == '{' or s[i] == ')' or
                s[i] == ']' or s[i] == '}'):
            array.append(s[i])
        i = i + 1

    if len(array) == 0:
        return True
    if len(array) % 2 != 0:
        return False
    # print(array)
    if array[0] == ')' or array[0] == ']' or array[0] == '}':
        return False

    new_array = []
    new_array.append(array.pop(0))
    i = 0
    while i < len(array):
        if array[i] == '(' or array[i] == '[' or array[i] == '{':
            new_array.append(array.pop(i))
        elif (new_array[-1] == '(' and array[i] == ')' or new_array[-1] == '['
                and array[i] == ']' or
                new_array[-1] == '{' and array[i] == '}'):
            new_array.pop()
            array.pop(i)
        elif ((new_array[-1] == '(' or new_array[-1] == '[' or
               new_array[-1] == '{') and (array[i] == '(' or
              array[i] == '[' or array[i] == '{')):
            i = i + 1
        else:
            return False
    return True


def main():
    s = "[]"
    print(bracket_validator(s))


main()
