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


class Flower(Plant):
    def __init__(self, name: str, height: int, age: int, color: str):
        super().__init__(name, height, age)
        self.color = color

    def bloom(self):
        print(f"{self.name} is blooming!")


class Tree(Plant):
    def __init__(self, name: str, height: int, age: int, trunk_diameter: int):
        super().__init__(name, height, age)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self):
        shade = self.get_height() * self.trunk_diameter
        print(f"{self.name} is producing {shade} square "
              "meters of shade")


class Vegetable(Plant):
    def __init__(self, name: str, height: int, age: int, harvest_season: str,
                 nutritional_value: str):
        super().__init__(name, height, age)
        self.harvest_season = harvest_season
        self.nutritional_value = nutritional_value


def ft_plant_types():
    rose = Flower("Rose", 20, 12, "red")
    orchid = Flower("Orchid", 10, 35, "white")
    oak = Tree("Oak", 500, 1825, 50)
    birch = Tree("Birch", 348, 689, 69)
    tomato = Vegetable("Tomato", 80, 90, "summer", "vitamin C")
    carrot = Vegetable("Carrot", 35, 23, "spring", "vitamin A")
    print("=== Garden Plant Types ===")
    print()
    print(f"{rose.name} (Flower): {rose.get_height()}cm,"
          f" {rose.get_age()} days, {rose.color} color")
    rose.bloom()
    print()
    print(f"{orchid.name} (Flower): {orchid.get_height()}cm,"
          f" {orchid.get_age()} days, {orchid.color} color")
    orchid.bloom()
    print()
    print(f"{oak.name} (Tree): {oak.get_height()}cm,"
          f" {oak.get_age()} days, {oak.trunk_diameter}cm diameter")
    oak.produce_shade()
    print()
    print(f"{birch.name} (Tree): {birch.get_height()}cm,"
          f" {birch.get_age()} days, {birch.trunk_diameter}cm diameter")
    birch.produce_shade()
    print()
    print(f"{tomato.name} (Vegetable): {tomato.get_height()}cm,"
          f" {tomato.get_age()} days, {tomato.harvest_season} harvest")
    print(f"{tomato.name} is rich in {tomato.nutritional_value}")
    print()
    print(f"{carrot.name} (Vegetable): {carrot.get_height()}cm,"
          f" {carrot.get_age()} days, {carrot.harvest_season} harvest")
    print(f"{carrot.name} is rich in {carrot.nutritional_value}")


if __name__ == "__main__":
    ft_plant_types()
