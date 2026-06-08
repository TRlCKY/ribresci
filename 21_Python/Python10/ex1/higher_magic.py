from typing import Callable


def fireball(target: str, power: int) -> str:
    return f"Fireball spell hits {target} with a power of {power}"


def heal(target: str, power: int) -> str:
    return f"Heal spell heals {target} heals for {power} HP"


def poison(target: str, power: int) -> str:
    return f"Poison spell gives to {target} {power} damage every minute"


def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    def function() -> tuple[str, str]:
        str0 = spell1()
        str1 = spell2()
        return str0 + ", " + str1
    return function


def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    def function() -> str:
        first_str = base_spell()
        list0 = first_str.split(" ")
        new_str = ""
        x = len(list0)
        for element in list0:
            if element.isdigit() is False:
                new_str += element
                if x != 0:
                    new_str += " "
            else:
                new_power = int(element) * multiplier
                new_str += str(new_power)
                if x != 0:
                    new_str += " "
            x -= 1
        return new_str
    return function


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    def function() -> str:
        if condition is False:
            return "Spell fizzled"
        else:
            msg = spell()
            return msg
    return function


def spell_sequence(spells: list[Callable]) -> Callable:
    def function() -> list[str]:
        spell_list = []
        for spell in spells:
            if callable(spell):
                spell_list.append(spell())
            else:
                raise Exception("Cannot cast a spell")
        return spell_list
    return function


def main():
    print("=== Spell Combiner ===")
    try:
        print("Combining 2 spells:")
        print(f"'{fireball('Dragon', 5)}' and '{heal('Warrior', 3)}'")
        combined = spell_combiner(lambda: fireball("Dragon", 5),
                                  lambda: heal("Warrior", 3))
        if callable(combined):
            print("Spells combined:")
            print(combined())
        else:
            raise Exception("Cannot call new spell_combiner")
    except Exception as e:
        print(f"Got error: {e}")
    print()
    print("=== Power Amplifier ===")
    try:
        print(f"Amplifiyng the spell {fireball('Dragon', 5)} by 3 times")
        amplified = power_amplifier(lambda: fireball("Dragon", 5), 3)
        if callable(amplified):
            print("Spell amplified:")
            print(amplified())
        else:
            raise Exception("Cannot call new power_amplifier")
    except Exception as e:
        print(f"Got error: {e}")
    print()
    print("=== Conditional Caster ===")
    try:
        print("Trying to cast a spell:")
        condition = conditional_caster(True, lambda: fireball("Dragon", 5))
        if callable(condition):
            print(condition())
        else:
            raise Exception("Cannot call new conditional_caster")
    except Exception as e:
        print(f"Got error: {e}")
    try:
        print("Trying to cast a spell a second time:")
        condition = conditional_caster(False, lambda: fireball("Dragon", 5))
        if callable(condition):
            print(condition())
        else:
            raise Exception("Cannot call new conditional_caster")
    except Exception as e:
        print(f"Got error: {e}")
    print()
    print("=== Spell Sequence ===")
    try:
        print("Creating a sequence of spell:")
        spell_list = [lambda: fireball("Dragon", 5),
                      lambda: heal("Warrior", 3),
                      lambda: poison("Fairy", 1)]
        sequence = spell_sequence(spell_list)
        if callable(sequence):
            print(sequence())
        else:
            raise Exception("Cannot call new spell_sequence")
    except Exception as e:
        print(f"Got error: {e}")


if __name__ == "__main__":
    main()
