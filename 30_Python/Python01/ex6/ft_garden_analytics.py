class Plant():
    class Stats():
        def __init__(self):
            self.set_n_show(0)
            self.set_n_age(0)
            self.set_n_grow(0)
            self.set_n_shade(0)

        def set_n_shade(self, n_shade: int):
            if n_shade >= 0:
                self._n_shade = n_shade

        def get_n_shade(self) -> int:
            return self._n_shade

        def set_n_show(self, n_show: int):
            if n_show >= 0:
                self._n_show = n_show

        def get_n_show(self) -> int:
            return self._n_show

        def set_n_age(self, n_age: int):
            if n_age >= 0:
                self._n_age = n_age

        def get_n_age(self) -> int:
            return self._n_age

        def set_n_grow(self, n_grow: int):
            if n_grow >= 0:
                self._n_grow = n_grow

        def get_n_grow(self) -> int:
            return self._n_grow

        def add_grow(self):
            self.set_n_grow(self.get_n_grow() + 1)

        def add_age(self):
            self.set_n_age(self.get_n_age() + 1)

        def add_show(self):
            self.set_n_show(self.get_n_show() + 1)

        def add_shade(self):
            self.set_n_shade(self.get_n_shade() + 1)

    def __init__(self, name: str, height: float, age: int):
        self.name = name
        self.set_height(height)
        self.set_age(age)
        self._stats = Plant.Stats()

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
        print(f"{self.name}: {self._height}cm, {self._age} days old")
        self._stats.add_show()

    @staticmethod
    def check_age(age):
        if (age >= 365):
            print(f"Is {age} days more than a year? -> True")
        else:
            print(f"Is {age} days more than a year? -> False")

    @classmethod
    def anonymous_plant(cls, name: str, height: float, age: int):
        cls.name = name
        cls.height = height
        cls.age = age


class Flower(Plant):
    def __init__(self, name: str, height: float, age: int, color: str,
                 bloom: bool):
        super().__init__(name, height, age)
        self.color = color
        self.set_bloom(bloom)

    def get_bloom(self) -> bool:
        return self._bloom

    def set_bloom(self, bloom: bool):
        self._bloom = bloom

    def bloom(self):
        self.set_bloom(True)

    def grow(self, height: float):
        new_height = self.get_height() + height
        self.set_height(new_height)
        self._stats.add_grow()

    def show(self):
        print(f"{self.name}: {self.get_height():.1f}cm, {self.get_age()}"
              " days old")
        print(f" Color: {self.color}")
        if self.get_bloom() is False:
            print(f" {self.name} has not bloomed yet")
        else:
            print(f" {self.name} is blooming beautifully!")
        self._stats.add_show()


class Seed(Flower):
    def __init__(self, name: str, height: float, age: int, color: str,
                 seed_number: int, bloom: int):
        super().__init__(name, height, age, color, bloom)
        self.set_seed_number(seed_number)
        self.set_bloom(bloom)

    def get_seed_number(self) -> int:
        return self._seed_number

    def set_seed_number(self, seed_number: int):
        if seed_number >= 0:
            self._seed_number = seed_number

    def get_bloom(self) -> bool:
        return self._bloom

    def set_bloom(self, bloom: bool):
        self._bloom = bloom

    def bloom(self):
        self.set_bloom(True)
        self.set_seed_number(42)

    def show(self):
        print(f"{self.name}: {self.get_height():.1f}cm, {self.get_age()}"
              " days old")
        print(f" Color: {self.color}")
        if self.get_bloom() is False:
            print(f" {self.name} has not bloomed yet")
        else:
            print(f" {self.name} is blooming beautifully!")
        print(f" Seeds: {self.get_seed_number()}")
        self._stats.add_show()

    def grow(self, days):
        new_height = self.get_height()
        new_age = self.get_age()
        for i in range(days):
            new_height = new_height + 1.5
        self.set_age(new_age)
        self._stats.add_grow()

    def age(self, days: int):
        self.set_age(self.get_age() + days)
        self._stats.add_age()


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
        print(f"{self.name}: {self.get_height():.1f}cm, {self.get_age()}"
              " days old")
        print(f" Trunk diameter: {self.get_trunk_diameter():.1f}cm")
        self._stats.add_show()

    def produce_shade(self):
        print(f"[asking the {self.name} to produce shade]")
        print(f"Tree {self.name} now produces a shade of "
              f"{self.get_height():.1f}cm "
              f"long and {self.get_trunk_diameter():.1f}cm wide.")
        self._stats.add_shade()


def show_stats(stats, check: int):
    print(f"Stats: {stats.get_n_grow()} grow, {stats.get_n_age()}"
          f" age, {stats.get_n_show()} show")
    if check == 1:
        print(f" {stats.get_n_shade()} shade")


def ft_garden_analytics():
    print("=== Garden statistics ===")
    print("=== Check year-old")
    p1 = Plant("Bamboo", 12, 30)
    p2 = Plant("Orchid", 34, 400)
    p1.check_age(p1.get_age())
    p2.check_age(p2.get_age())
    print()
    print("=== Flower")
    rose = Flower("Rose", 15, 10, "red", False)
    rose.show()
    print(f"[statistics for {rose.name}]")
    show_stats(rose._stats, 0)
    print(f"[asking thr {rose.name} to grow and bloom]")
    rose.grow(8)
    rose.bloom()
    rose.show()
    print(f"[statistics for {rose.name}]")
    show_stats(rose._stats, 0)
    print()
    print("=== Tree")
    oak = Tree("Oak", 200, 365, 5)
    oak.show()
    print(f"[statistics for {oak.name}]")
    show_stats(oak._stats, 1)
    oak.produce_shade()
    print(f"[statistics for {oak.name}]")
    show_stats(oak._stats, 1)
    print()
    print("=== Seed")
    sunflower = Seed("Sunflower", 80, 45, "yellow", 0, False)
    sunflower.show()
    print(f"[make {sunflower.name} grow, age and bloom]")
    sunflower.grow(20)
    sunflower.age(20)
    sunflower.bloom()
    sunflower.show()
    print(f"[statistics for {sunflower.name}]")
    show_stats(sunflower._stats, 0)
    print()
    print("=== Anonymous")
    p3 = Plant("Unknown plant", 0.0, 0)
    p3.show()
    print(f"[statistics for {p3.name}]")
    show_stats(p3._stats, 0)


if __name__ == "__main__":
    ft_garden_analytics()
