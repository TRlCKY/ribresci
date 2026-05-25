import random


first_list = ["Jojo", "Gabibbo", "leone il cane fifone", "Gumball",
              "gianfrancioschio", "Dr. Doofenschmirtz",
              "perry l'ornitorinco"]


def capitalize_list(first_list: list) -> list:
    return [x.capitalize() for x in first_list]


def create_list() -> list:
    return first_list


def capitalize_only(first_list: list) -> list:
    return [x for x in first_list if x == x.capitalize()]


def create_dict(first_list: list) -> dict[str, int]:
    return {x: random.randint(1, 1000) for x in first_list}


def get_avg(values: list) -> float:
    return (sum(values) / len(values))


def create_dict_capitalize(players: dict[str, int],
                           average: float) -> dict[str, int]:
    return {x: score for (x, score) in players.items() if score > average}


def main():
    print("=== Game Data Alchemist ===")
    print()
    list1 = create_list()
    print(f"Initial list of players: {list1}\n")
    list2 = capitalize_list(list1)
    print(f"New list with all names capitalized: {list2}\n")
    list3 = capitalize_only(list1)
    print(f"New list of capitalized names only: {list3}\n")
    players = dict()
    players = create_dict(list2)
    print(f"Score dict: {players}")
    average = 0.0
    values = list(players.values())
    average = get_avg(values)
    print(f"Score average: {average:.2f}")
    high_score = dict()
    high_score = create_dict_capitalize(players, average)
    print(f"High scores: {high_score}")


if __name__ == "__main__":
    main()
