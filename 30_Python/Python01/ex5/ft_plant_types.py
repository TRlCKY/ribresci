class Plant():
    def __init__(self, name: str, height: int, age: int):
        self.name = name
        self.set_height(height)
        self.set_age(age)

    def set_height(self, height: int):
        if height >= 0:
            self.__height = height

    def set_age(self, age: int):
        if age >= 0:
            self.__age = age

    def get_height(self) -> int:
        return self.__height

    def get_age(self) -> int:
        return self.__age

    def show(self):
        print(f"{self.name}: {self.get_height():.1f}cm, {self.get_age()}"
              " days old")


class Flower(Plant):
    def __init__(self, name: str, height: int, age: int, color: str):
        super().__init__(name, height, age)
        self.color = color

    def show(self):
        print(f"{self.name}: {self.get_height():.1f}cm, {self.get_age()}"
              " days old")
        print(f" Color: {self.color}")

    def bloom(self):
        self.show()
        print(f" {self.name} has not bloomed yet")
        print(f"[asking the {self.name} to bloom]")
        self.show()
        print(f" {self.name} is blooming beutifully!")
        print()


class Tree(Plant):
    def __init__(self, name: str, height: int, age: int, trunk_diameter: int):
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def show(self):
        print(f"{self.name}: {self.get_height():.1f}cm, {self.get_age()}"
              " days old")
        print(f" Trunk diameter: {self.trunk_diameter:.1f}cm")

    def produce_shade(self):
        self.show()
        print(f"[asking the {self.name} to produce shade]")
        print(f"Tree {self.name} now produces a shade of "
              f"{self.get_height():.1f}cm "
              f"long and {self.trunk_diameter:.1f}cm wide.")
        print()


class Vegetable(Plant):
    def __init__(self, name: str, height: int, age: int, harvest_season: str,
                 nutritional_value: int):
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value

    def show(self):
        print(f"{self.name}: {self.get_height():.1f}cm, {self.get_age()}"
              " days old")
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {self.nutritional_value}")

    def grow(self, days: int):
        self.show()
        print(f"[make {self.name} grow and age for {days} days]")
        new_age = self.get_age()
        new_height = self.get_height()
        new_age = new_age + days
        new_value = self.nutritional_value
        for i in range(days):
            new_height = new_height + 2.1
            new_value = new_value + 1
        self.set_height(new_height)
        self.set_age(new_age)
        self.nutritional_value = new_value
        self.show()
        print()


def ft_plant_types():
    rose = Flower("Rose", 15, 10, "red")
    orchid = Flower("Orchid", 10, 35, "white")
    oak = Tree("Oak", 200, 365, 5)
    birch = Tree("Birch", 348, 689, 69)
    tomato = Vegetable("Tomato", 5, 10, "April", 0)
    carrot = Vegetable("Carrot", 35, 23, "May", 20)
    print("=== Garden Plant Types ===")
    print("=== Flower")
    rose.bloom()
    orchid.bloom()
    print("=== Tree")
    oak.produce_shade()
    birch.produce_shade()
    print("=== Vegetable")
    tomato.grow(20)
    carrot.grow(5)


if __name__ == "__main__":
    ft_plant_types()
