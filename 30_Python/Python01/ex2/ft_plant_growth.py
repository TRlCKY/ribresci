class Plant():
    def __init__(self, name: str, height: int, starting_age: int):
        self.name = name
        self.height = height
        self.starting_age = starting_age

    def age(self):
        self.starting_age = self.starting_age + 1

    def grow(self):
        self.height = self.height + 0.8

    def show(self):
        print(f"{self.name}: {round(self.height, 1)}cm, {self.starting_age}"
              " days old")


def ft_plant_growth():
    print("=== Garden Plant Growth ===")
    plant = Plant("Rose", 25, 30)
    plant.show()
    total_growth = 0
    day = 1
    for i in range(7):
        print(f"=== Day {day} ===")
        day = day + 1
        plant.grow()
        plant.age()
        total_growth = total_growth + 0.8
        plant.show()
    print(f"Growth this week: {total_growth}cm")


if __name__ == "__main__":
    ft_plant_growth()
