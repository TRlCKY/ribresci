class Plant():
    def __init__(self, name: str, height: float, age: int):
        self.name = name
        self.set_height(height)
        self.set_age(age)

    def set_height(self, height: float):
        if height >= 0:
            self._height = height

    def set_age(self, age: int):
        if age >= 0:
            self._age = age

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age

    def show(self):
        print(f"{self.name}: {self.get_height():.1f}cm,"
              f" {self.get_age()} days old")


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int,
                 color: str):
        super().__init__(name, height, age)
        self.color = color

    def show(self):
        print(f"{self.name}: {self.get_height():.1f}cm,"
              f" {self.get_age()} days old")
        print(f" Color: {self.color}")

    def bloom(self):
        self.show()
        print(f" {self.name} has not bloomed yet")
        print(f"[asking the {self.name} to bloom]")
        self.show()
        print(f" {self.name} is blooming beutifully!")
        print()


class Tree(Plant):
    def __init__(self, name: str, height: float, age: int,
                 trunk_diameter: int):
        super().__init__(name, height, age)
        self.set_trunk_diameter(trunk_diameter)

    def get_trunk_diameter(self) -> int:
        return self._trunk_diameter

    def set_trunk_diameter(self, trunk_diameter: int):
        if trunk_diameter >= 0:
            self._trunk_diameter = trunk_diameter

    def show(self):
        print(f"{self.name}: {self.get_height():.1f}cm,"
              f" {self.get_age()} days old")
        print(f" Trunk diameter: {self.get_trunk_diameter():.1f}cm")

    def produce_shade(self):
        self.show()
        print(f"[asking the {self.name} to produce shade]")
        print(f"Tree {self.name} now produces a shade of "
              f"{self.get_height():.1f}cm "
              f"long and {self.get_trunk_diameter():.1f}cm wide.")
        print()


class Vegetable(Plant):
    def __init__(self, name: str, height: float, age: int,
                 harvest_season: str, nutritional_value: int):
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.set_nutritional_value(nutritional_value)

    def get_nutritional_value(self) -> int:
        return self._nutritional_value

    def set_nutritional_value(self, nutritional_value: int):
        if nutritional_value >= 0:
            self._nutritional_value = nutritional_value

    def show(self):
        print(f"{self.name}: {self.get_height():.1f}cm,"
              f" {self.get_age()} days old")
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {self.get_nutritional_value()}")

    def grow(self, days: int):
        new_height = self.get_height()
        new_value = self.get_nutritional_value()
        for i in range(days):
            new_height = new_height + 2.1
            new_value = new_value + 1
        self.set_height(new_height)
        self.set_nutritional_value(new_value)

    def age(self, days: int):
        new_age = self.get_age()
        new_age = new_age + days
        self.set_age(new_age)


def ft_plant_types():
    rose = Flower("Rose", 15, 10, "red")
    orchid = Flower("Orchid", 10, 35, "white")
    oak = Tree("Oak", 200, 365, 5)
    birch = Tree("Birch", 348, 689, 69)
    tomato = Vegetable("Tomato", 5, 10, "April", 0)
    carrot = Vegetable("Carrot", 35, 23, "May", 0)
    print("=== Garden Plant Types ===")
    print("=== Flower")
    rose.bloom()
    orchid.bloom()
    print("=== Tree")
    oak.produce_shade()
    birch.produce_shade()
    print("=== Vegetable")
    tomato.show()
    print(f"[make {tomato.name} grow and age for 20 days]")
    tomato.grow(20)
    tomato.age(20)
    tomato.show()
    print()
    carrot.show()
    print(f"[make {carrot.name} grow and age for 5 days]")
    carrot.grow(5)
    carrot.age(5)
    carrot.show()


if __name__ == "__main__":
    ft_plant_types()
