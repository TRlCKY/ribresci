from ex2.creatures import CreatureFactory, FlameFactory, AquaFactory
from ex2.creatures import TransformCreatureFactory, HealingCreatureFactory
from ex2.battle_strategy import BattleStrategy, NormalStrategy
from ex2.battle_strategy import AggressiveStrategy, DefensiveStrategy


def battle(opponents: list[tuple[CreatureFactory, BattleStrategy]]):
    print("### Tournament ###")
    print(f"{len(opponents)} opponents involved")
    i = len(opponents)
    e = i - 1
    j = 0
    k = j + 1
    while j <= i:
        k = j + 1
        while k <= e:
            if j != k:
                print("# Battle #")
                tuple0 = opponents[j]
                opp0 = tuple0[0]
                battle0 = tuple0[1]
                tuple1 = opponents[k]
                opp1 = tuple1[0]
                battle1 = tuple1[1]
                c0 = opp0.create_base()
                c1 = opp1.create_base()
                print(f"{c0.describe()} ({battle0.name})")
                print(" vs.")
                print(f"{c1.describe()} ({battle1.name})")
                print(" now fight!")
                battle0.act(c0)
                battle1.act(c1)
                print()
            k += 1
        j += 1


def main():
    fire = FlameFactory()
    water = AquaFactory()
    grass = HealingCreatureFactory()
    norm = TransformCreatureFactory()
    normal = NormalStrategy()
    aggro = AggressiveStrategy()
    bulky = DefensiveStrategy()
    try:
        print("Tournament 0 (Basic)")
        opponents = [(fire, normal), (grass, bulky)]
        # print(opponents)
        battle(opponents)
    except Exception as e:
        print(f"Battle error: {e}")
    print()
    try:
        print("Tournament 1 (error)")
        opponents = [(fire, aggro), (grass, bulky)]
        # print(opponents)
        battle(opponents)
    except Exception as e:
        print(f"Battle error: {e}")
    print()
    try:
        print("Tournament 2 (multiple)")
        opponents = [(water, normal), (grass, bulky), (norm, aggro)]
        # print(opponents)
        battle(opponents)
    except Exception as e:
        print(f"Battle error: {e}")


if __name__ == "__main__":
    main()
