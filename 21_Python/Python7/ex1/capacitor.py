from ex1.creature_factories import TransformCreatureFactory
from ex1.creature_factories import HealingCreatureFactory


def capacitator():
    healing = HealingCreatureFactory()
    print("Testing Creature with healing capability")
    print(" base:")
    sprout = healing.create_base()
    print(sprout.describe())
    print(sprout.attack())
    print(sprout.heal("itself"))
    print(" evolved:")
    bloom = healing.create_evolved()
    print(bloom.describe())
    print(bloom.attack())
    print(bloom.heal("itself and others"))
    print()
    transform = TransformCreatureFactory()
    print("Testing Creature with transform capability")
    print(" base:")
    shift = transform.create_base()
    print(shift.describe())
    print(shift.attack())
    print(shift.transform())
    print(shift.attack())
    print(shift.revert())
    print(" evolved:")
    morph = transform.create_evolved()
    print(morph.describe())
    print(morph.attack())
    print(morph.transform())
    print(morph.attack())
    print(morph.revert())


if __name__ == "__main__":
    capacitator()
