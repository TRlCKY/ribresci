class Plant():
    def __init__(self, name: str, height: int, age: int):
        self.name = name
        self.height = height
        self.age = age


def age(age: int):
    age = age + 1
    return age


def grow(height: int):
    height = height + 0.8
    return height


def show(self):
    print(f"{self.name}: {round(self.height, 1)}cm, {self.age} days old")


def ft_plant_growth():
    print("=== Garden Plant Growth ===")
    plant = Plant("Rose", 25, 30)
    total_growth = -1
    day = 1
    for i in range(7):
        print(f"=== Day {day} ===")
        day = day + 1
        show(plant)
        plant.height = grow(plant.height)
        plant.age = age(plant.age)
        total_growth = total_growth + 1
    print(f"Growth this week: {total_growth}cm")


if __name__ == "__main__":
    ft_plant_growth()
