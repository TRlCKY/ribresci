class SecurePlant:
    def __init__(self, name: str, height: int, age: int):
        self.name = name
        self.set_height(height)
        self.set_age(age)

    def get_height(self) -> int:
        return self.__height

    def get_age(self) -> int:
        return self.__age

    def set_height(self, height: int):
        if height >= 0:
            self.__height = height

    def set_age(self, age: int):
        if age >= 0:
            self.__age = age


def ft_garden_security():
    print("=== Garden Security System ===")
    GardenName = ["Rose", "Orchid", "Bamboo"]
    GardenHeight = [25, -1, 40]
    GardenAge = [30, 23, -4]
    for i in range(3):
        if GardenAge[i] >= 0 and GardenHeight[i] >= 0:
            print(f"Plant created: {GardenName[i]}")
            print(f"Height updated: {GardenHeight[i]}cm [OK]")
            print(f"Age updated: {GardenAge[i]}cm [OK]")
            print()
            p = SecurePlant(GardenName[i], GardenHeight[i], GardenAge[i])
        if GardenAge[i] < 0:
            print("Invalid operation attempted: age "
                  f"{GardenAge[i]} [REJECTED]")
            print("Security: Negative age rejected")
            print()
        if GardenHeight[i] < 0:
            print("Invalid operation attempted: height "
                  f"{GardenHeight[i]}cm [REJECTED]")
            print("Security: Negative height rejected")
            print()
    print(f"Current plant: {p.name} ({p.get_height()}cm, "
          f"{p.get_age()} days)")


if __name__ == "__main__":
    ft_garden_security()
