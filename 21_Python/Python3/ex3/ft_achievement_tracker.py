import random


def main():
    print("=== Achievement Tracker System ===")
    print()
    name1 = "Alice"
    achiev1 = gen_player_achievements()
    name2 = "Bob"
    achiev2 = gen_player_achievements()
    name3 = "Charlie"
    achiev3 = gen_player_achievements()
    name4 = "Dylan"
    achiev4 = gen_player_achievements()
    print(f"Player {name1}: {achiev1}")
    print(f"Player {name2}: {achiev2}")
    print(f"Player {name3}: {achiev3}")
    print(f"Player {name4}: {achiev4}")
    print()
    d_achievements = set()
    d_achievements = d_achievements.union(achiev1)
    d_achievements = d_achievements.union(achiev2)
    d_achievements = d_achievements.union(achiev3)
    d_achievements = d_achievements.union(achiev4)
    print(f"All distinct achievements: {d_achievements}")
    print()
    c_achievements = set()
    c_achievements = c_achievements.union(achiev1)
    c_achievements = c_achievements.intersection(achiev2)
    c_achievements = c_achievements.intersection(achiev3)
    c_achievements = c_achievements.intersection(achiev4)
    print(f"Common achievements: {c_achievements}")
    unique1 = set()
    unique1 = unique1.union(achiev1)
    unique1 = unique1.difference(achiev2)
    unique1 = unique1.difference(achiev3)
    unique1 = unique1.difference(achiev4)
    if len(unique1) == 0:
        print(f"Only {name1} has: set()")
    else:
        print(f"Only {name1} has: {unique1}")
    unique2 = set()
    unique2 = unique2.union(achiev2)
    unique2 = unique2.difference(achiev1)
    unique2 = unique2.difference(achiev3)
    unique2 = unique2.difference(achiev4)
    if len(unique2) == 0:
        print(f"Only {name2} has: set()")
    else:
        print(f"Only {name2} has: {unique2}")
    unique3 = set()
    unique3 = unique3.union(achiev3)
    unique3 = unique3.difference(achiev2)
    unique3 = unique3.difference(achiev1)
    unique3 = unique3.difference(achiev4)
    if len(unique3) == 0:
        print(f"Only {name3} has: set()")
    else:
        print(f"Only {name3} has: {unique3}")
    unique4 = set()
    unique4 = unique4.union(achiev4)
    unique4 = unique4.difference(achiev2)
    unique4 = unique4.difference(achiev3)
    unique4 = unique4.difference(achiev1)
    if len(unique4) == 0:
        print(f"Only {name4} has: set()")
    else:
        print(f"Only {name4} has: {unique4}")
    print()
    all_achiev = {"They grow so fast", "Isn't it an iron pick?",
                  "The end?", "Stone age", "Cover me with diamonds",
                  "Iron man", "Sweet dreams are made for this", "Diamonds",
                  "How did we get here?", "hot stuff"}
    missing1 = set()
    missing1 = missing1.union(all_achiev)
    missing1 = missing1.difference(achiev1)
    print(f"{name1} is missing: {missing1}")
    missing2 = set()
    missing2 = missing2.union(all_achiev)
    missing2 = missing2.difference(achiev2)
    print(f"{name2} is missing: {missing2}")
    missing3 = set()
    missing3 = missing3.union(all_achiev)
    missing3 = missing3.difference(achiev3)
    print(f"{name3} is missing: {missing3}")
    missing4 = set()
    missing4 = missing4.union(all_achiev)
    missing4 = missing4.difference(achiev4)
    print(f"{name4} is missing: {missing4}")


def gen_player_achievements() -> set[str]:
    achievements = {"They grow so fast", "Isn't it an iron pick?",
                    "The end?", "Stone age", "Cover me with diamonds",
                    "Iron man", "Sweet dreams", "Diamonds", "hot stuff",
                    "How did we get here?"}
    num = random.randint(1, len(achievements))
    return set(random.sample(list(achievements), num))


if __name__ == "__main__":
    main()
