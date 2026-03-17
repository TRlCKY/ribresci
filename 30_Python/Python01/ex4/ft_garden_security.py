class SecurePlant:
    def __init__(self, name: str, height: int, age: int):
        self.name = name
        self.height = set_height(self, height)
        self.age = set_age(self, age)

    def get_height(self) -> int:
        return self.height

    def get_age(self) -> int:
        return self.age


def set_height(self, height: int):
    self.height = height


def set_age(self, age: int):
    self.age = age


def ft_garden_security():
    print("=== Garden Security System ===")
    plant = SecurePlant("Rose", 25, 30)
    if (plant.get_height() >= 0 and plant.get_age() >= 0):
        print(f"Plant created: {plant.name}")
        print(f"Age updated: {plant.get_age()}cm [OK]")
        print(f"Height updated: {plant.get_height()}cm [OK]")
    if (plant.get_height() < 0):
        print(f"Invalid operation attempted: height {plant.get_height()} [REJECTED]")
        print("Security: Negative height rejected")
    if (plant.age < 0):
        print(f"Invalid operation attempted: age {plant.age} [REJECCTED]")
        print("Security: Negative age rejected")
    plant = SecurePlant("Rose", -1, -5)
    if (plant.height >= 0 and plant.age >= 0):
        print(f"Plant created: {plant.name}")
        print(f"Age updated: {plant.age}cm [OK]")
        print(f"Height updated: {plant.height}cm [OK]")
    if (plant.height < 0):
        print(f"Invalid operation attempted: height {plant.height} [REJECCTED]")
        print("Security: Negative height rejected")
    if (plant.age < 0):
        print(f"Invalid operation attempted: age {plant.age} [REJECCTED]")
        print("Security: Negative age rejected")


if __name__ == "__main__":
    ft_garden_security()
