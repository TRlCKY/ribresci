def iterate(days):
    if days != 1:
        iterate(days - 1)
    print(f"Day {days}")


def ft_count_harvest_recursive():
    days = int(input("Days until havest: "))
    iterate(days)
    print("Harvest time!")


# ft_count_harvest_recursive()
