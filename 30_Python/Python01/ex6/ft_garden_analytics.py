class Plant():
    def __init__(self, name: str, height: int, age: int, n_grow: int,
                 n_age: int, n_show: int):
        self.name = name
        self.set_height(height)
        self.set_age(age)
        self.n_grow = 0
        self.n_age = 0
        self.n_show = 0

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
        self.n_show = self.n_show + 1

    @staticmethod
    def check_age(age):
        if (age >= 365):
            print(f"Is {age} days more than a year? -> True")
        else:
            print(f"Is {age} days more than a year? -> False")

    @classmethod
    def anonymous_plant(cls, name: str, height: int, age: int):
        def __init__(cls, name: str, height: int, age: int):
            cls.name = "Unknown plant"
            cls.height = 0
            cls.age = 0


class Flower(Plant):
    def __init__(self, name: str, height: int, age: int, color: str):
        super().__init__(name, height, age)
        self.color = color

    def bloom(self):
        self.show()
        print(f" {self.name} has not bloomed yet")
        print(f"[asking the {self.name} to bloom]")
        self.show()
        print(f" {self.name} is blooming beutifully!")
        print()

    def show(self):
        print(f"{self.name}: {self.get_height():.1f}cm, {self.get_age()}"
              " days old")
        print(f" Color: {self.color}")
        if self.bloom is False:
            print(f" {self.name} has not bloomed yet")
        else:
            print(f" {self.name} is blooming beautifully!")
        print(f" Seeds: {self.seed_number}")
        self.n_show = self.n_show + 1


class Seed(Flower):
    def __init__(self, name: str, height: int, age: int, color: str,
                 seed_number: int, bloom: bool):
        super().__init__(name, height, age, color)
        self.seed_number = seed_number
        self.bloom = False

    def show(self):
        print(f"{self.name}: {self.get_height():.1f}cm, {self.get_age()}"
              " days old")
        print(f" Color: {self.color}")
        if self.bloom is False:
            print(f" {self.name} has not bloomed yet")
        else:
            print(f" {self.name} is blooming beautifully!")
        print(f" Seeds: {self.seed_number}")
        self.n_show = self.n_show + 1

    def grow(self, days: int):
        new_height = self.get_height()
        new_age = self.get_age()
        for i in range(20):
            new_height = new_height + 1.5
            new_age = new_age + 1
        self.set_age(new_age)
        self.set_height(new_height)


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


def ft_garden_analytics():
    print("=== Garden statistics ===")
    print("=== Check year-old")
    p1 = Plant("Bamboo", 12, 30)
    p2 = Plant("Orchid", 34, 400)
    p1.check_age(p1.get_age)
    p2.check_age(p2.get_age)
    print()
    print("=== Flower")
    rose = Flower("Rose", 15, 10, "red")
    rose.show()
    print()


if __name__ == "__main__":
    ft_garden_analytics()
