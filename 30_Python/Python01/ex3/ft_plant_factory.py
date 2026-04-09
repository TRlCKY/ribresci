class Plant():
    def __init__(self, name: str, height: int, age: int):
        self.name = name
        self.height = height
        self.age = age


GardenData = [Plant("Rose", 25, 30), Plant("Sunflower", 80, 45),
              Plant("Cactus", 15, 120), Plant("Orchid", 35, 25),
              Plant("Bamboo", 50, 12)]


def show(self):
    print(f"Created: {self.name}: {self.height:.1f}cm, {self.age} days old")


def ft_plant_factory():
    print("=== Plant Factory Output ===")
    for i in range(5):
        plant = GardenData[i]
        show(plant)


if __name__ == "__main__":
    ft_plant_factory()
