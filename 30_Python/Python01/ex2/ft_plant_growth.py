class Plant():
    def __init__(self, Name: str, Height: int, Age: int):
        self.Name = Name
        self.Height = Height
        self.Age = Age


GardenData = [Plant("Rose", 25, 30), Plant("Sunflower", 80, 45),
              Plant("Cactus", 15, 120)]


def age(Age: int):
    Age = Age + 1
    return Age


def grow(Height: int):
    Height = Height + 1
    return Height


def get_info(self):
    print(f"{self.Name}: {self.Height}cm, {self.Age} days old")


def ft_plant_growth():
    print("=== Day 1 ===")
    for i in range(3):
        total_growth = 0
        plant = GardenData[i]
        get_info(plant)
        for i in range(6):
            plant.Height = grow(plant.Height)
            plant.Age = age(plant.Age)
            total_growth = total_growth + 1
    print("=== Day 7 ===")
    for i in range(3):
        plant = GardenData[i]
        get_info(plant)
        print(f"Growth this week: +{total_growth}cm")


if __name__ == "__main__":
    ft_plant_growth()
