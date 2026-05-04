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


GardenData = [Plant("Rose", 25, 30), Plant("Sunflower", 80, 45),
              Plant("Cactus", 15, 120), Plant("Orchid", 35, 25),
              Plant("Bamboo", 50, 12)]


def show(self):
    print(f"Created: {self.name}: {self.height:.1f}cm, {self.starting_age}"
          " days old")


def ft_plant_factory():
    print("=== Plant Factory Output ===")
    for i in range(5):
        plant = GardenData[i]
        show(plant)


if __name__ == "__main__":
    ft_plant_factory()
