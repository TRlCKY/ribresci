class Plant:
    def __init__(self, Name: str, Height: int, Age: int):
        self.Name = Name
        self.Height = Height
        self.Age = Age


GardenData = [Plant("Rose", 25, 30), Plant("Sunflower", 80, 45),
              Plant("Cactus", 15, 120)]


def ft_garden_data():
    print("=== Garden Plant Registry ===")
    for i in range(3):
        plant = GardenData[i]
        print(f"{plant.Name}: {plant.Height}cm, {plant.Age} days old")


if __name__ == "__main__":
    ft_garden_data()
