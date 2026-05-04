class SecurePlant:
    def __init__(self, name: str, height: int, age: int):
        self.name = name
        self.set_height(height)
        self.set_age(age)

    def get_height(self) -> int:
        return self._height

    def get_age(self) -> int:
        return self._age

    def set_height(self, height: int):
        if height >= 0:
            self._height = height

    def set_age(self, age: int):
        if age >= 0:
            self._age = age


def check_values(self, height: int, age: int):
    if height >= 0 and age >= 0:
        self.set_height(height)
        self.set_age(age)
        print(f"Height updated: {self.get_height()}cm")
        print(f"Aeg updated: {self.get_age()}cm")
        print()
    if height < 0:
        print(f"{self.name}: Error, height can't be negative")
        print("Height update rejected")
    if age < 0:
        print(f"{self.name}: Error, age can't be negative")
        print("Age update rejected")
        print()


def ft_garden_security():
    print("=== Garden Security System ===")
    name = "Rose"
    height = 15
    age = 10
    rose = SecurePlant(name, height, age)
    print(f"Plant created: {rose.name}: {rose.get_height():.1f}cm, "
          f"{rose.get_age()} days old")
    print()
    height = 25
    age = 30
    check_values(rose, height, age)
    height = -1
    age = -5
    check_values(rose, height, age)
    print(f"Current state: {rose.name}: {rose.get_height():.1f}cm, "
          f"{rose.get_age()} days old")


if __name__ == "__main__":
    ft_garden_security()
