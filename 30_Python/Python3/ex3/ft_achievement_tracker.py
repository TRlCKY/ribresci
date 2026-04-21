import random


def main():
    name1 = "Alice"
    achiev1 = gen_player_achievements()
    name2 = "Bob"
    achiev2 = gen_player_achievements()
    name3 = "Charlie"
    achiev3 = gen_player_achievements()
    name4 = "Dylan"
    achiev4 = gen_player_achievements()
    print("=== Achievement Tracker System ===")
    print()
    print(f"Player {name1}: {achiev1}")
    print(f"Player {name2}: {achiev2}")
    print(f"Player {name3}: {achiev3}")
    print(f"Player {name4}: {achiev4}")
    print()
    d_achievements = {}
    d_achievements = achiev1.union(achiev2)
    d_achievements = d_achievements.union(achiev3)
    d_achievements = d_achievements.union(achiev4)
    print(f"All distinct achievements: {d_achievements}")
    print()
    c_achievements = {}
    c_achievements = achiev1.intersect(achiev2)
    c_achievements = c_achievements.intersect(achiev3)
    c_achievements = c_achievements.intersect(achiev4)
    print(f"Common achievements: {c_achievements}")
    unique1 = {}
    unique1 = achiev1.difference(achiev2)
    unique1 = unique1.difference(achiev3)
    unique1 = unique1.difference(achiev4)
    if len(unique1) == 0:
        print(f"Only {name1} has: set()")
    else:
        print(f"Only {name1} has: {unique1}")
    unique2 = {}
    unique2 = achiev2.difference(achiev1)
    unique2 = unique2.difference(achiev3)
    unique2 = unique2.difference(achiev4)
    if len(unique2) == 0:
        print(f"Only {name1} has: set()")
    else:
        print(f"Only {name1} has: {unique2}")
    unique3 = {}
    unique3 = achiev3.difference(achiev2)
    unique3 = unique3.difference(achiev1)
    unique3 = unique3.difference(achiev4)
    if len(unique3) == 0:
        print(f"Only {name1} has: set()")
    else:
        print(f"Only {name1} has: {unique3}")
    unique4 = {}
    unique4 = achiev4.difference(achiev2)
    unique4 = unique4.difference(achiev3)
    unique4 = unique4.difference(achiev1)
    if len(unique4) == 0:
        print(f"Only {name1} has: set()")
    else:
        print(f"Only {name1} has: {unique4}")
    print()
    all_achiev = {"They grow so fast", "Isn't it an iron pick?",
                  "The end?", "Stone age", "Cover me with diamonds",
                  "Iron man", "Sweet dreams are made for this", "Diamonds",
                  "How did we get here?", "hot stuff"}
    missing1 = {}
    missing1 = all_achiev.difference(achiev1)
    print(f"{name1} is missing: {missing1}")
    missing2 = {}
    missing2 = all_achiev.difference(achiev2)
    print(f"{name1} is missing: {missing2}")
    missing3 = {}
    missing3 = all_achiev.difference(achiev3)
    print(f"{name1} is missing: {missing3}")
    missing4 = {}
    missing4 = all_achiev.difference(achiev4)
    print(f"{name1} is missing: {missing4}")


def gen_player_achievements() -> dict[int, set[str]]:
    achievements = {"They grow so fast", "Isn't it an iron pick?",
                    "The end?", "Stone age", "Cover me with diamonds",
                    "Iron man", "Sweet dreams are made for this", "Diamonds",
                    "How did we get here?", "hot stuff"}
    new_achievements = {}
    num = random.randint(1, len(achievements))
    for i in range(num):
        new_achievements[num] = random.sample(achievements, len(achievements))
    return new_achievements


if __name__ == "__main__":
    main()
