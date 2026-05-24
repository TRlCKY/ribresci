from ex0 import FlameFactory, AquaFactory


def test_battle(f1: FlameFactory | AquaFactory,
                f2: FlameFactory | AquaFactory):
    try:
        if isinstance(f1, FlameFactory) or \
           isinstance(f1, AquaFactory):
            c1 = f1.create_base()
        if isinstance(f2, FlameFactory) or \
           isinstance(f2, AquaFactory):
            c2 = f2.create_base()
        print(c1.describe())
        print(" vs.")
        print(c2.describe())
        print(" fight!")
        print(c1.attack())
        print(c2.attack())
    except Exception as e:
        print(f"Got error: {e}")


def battle():
    fire = FlameFactory()
    flame = fire.create_base()
    pyro = fire.create_evolved()
    water = AquaFactory()
    aqua = water.create_base()
    torra = water.create_evolved()
    print("Testing factory")
    print(flame.describe())
    print(flame.attack())
    print(pyro.describe())
    print(pyro.attack())
    print()
    print("Testing factory")
    print(aqua.describe())
    print(aqua.attack())
    print(torra.describe())
    print(torra.attack())
    print()
    print("Testing battle")
    test_battle(fire, water)


if __name__ == "__main__":
    battle()
