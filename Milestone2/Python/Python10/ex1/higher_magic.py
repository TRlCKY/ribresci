from typing import Callable


def fireball(target: str, power: int) -> str:
    return f"Fireball spell hits {target} with a power of {power}"


def heal(target: str, power: int) -> str:
    return f"Heal spell heals {target} for {power} HP"


def poison(target: str, power: int) -> str:
    return f"Poison spell gives to {target} {power} damage every minute"


def cond(target: str, power) -> bool:
    if power >= 1 and isinstance(target, str) is True:
        return True
    return False


def spell_combiner(spell1: Callable, spell2: Callable) -> Callable:
    def function(target: str, power: int) -> tuple[str, str]:
        str0 = spell1(target, power)
        str1 = spell2(target, power)
        return (str0, str1)
    return function


def power_amplifier(base_spell: Callable, multiplier: int) -> Callable:
    def function(target: str, power: int) -> str:
        return base_spell(target, power * multiplier)
    return function


def conditional_caster(condition: Callable, spell: Callable) -> Callable:
    def function(target: str, power: int) -> str:
        if condition(target, power) is False:
            return "Spell fizzled"
        else:
            msg = spell(target, power)
            return msg
    return function


def spell_sequence(spells: list[Callable]) -> Callable:
    def function(target: str, power: int) -> list[str]:
        spell_list = []
        for spell in spells:
            if callable(spell):
                spell_list.append(spell(target, power))
            else:
                raise Exception("Cannot cast a spell")
        return spell_list
    return function


def main():
    print("=== Spell Combiner ===")
    try:
        print("Combining 2 spells:")
        print(f"'{fireball('Dragon', 5)}' and '{heal('Warrior', 3)}'")
        combined = spell_combiner(fireball, heal)
        if callable(combined):
            print("Spells combined:")
            print(combined("Dragon", 5))
        else:
            raise Exception("Cannot call new spell_combiner")
    except Exception as e:
        print(f"Got error: {e}")
    print()
    print("=== Power Amplifier ===")
    try:
        print("Amplifiyng the fireball spell by 3 times")
        amplified = power_amplifier(fireball, 3)
        if callable(amplified):
            print("Spell amplified:")
            print(amplified("Dragon", 5))
        else:
            raise Exception("Cannot call new power_amplifier")
    except Exception as e:
        print(f"Got error: {e}")
    print()
    print("=== Conditional Caster ===")
    try:
        print("Trying to cast a spell:")
        condition = conditional_caster(cond, fireball)
        if callable(condition):
            print(condition("Dragon", 5))
        else:
            raise Exception("Cannot call new conditional_caster")
    except Exception as e:
        print(f"Got error: {e}")
    try:
        print("Trying to cast a spell a second time:")
        if callable(condition):
            print(condition("Dragon", 0))
        else:
            raise Exception("Cannot call new conditional_caster")
    except Exception as e:
        print(f"Got error: {e}")
    print()
    print("=== Spell Sequence ===")
    try:
        print("Creating a sequence of spell:")
        spell_list = [fireball, heal, poison]
        sequence = spell_sequence(spell_list)
        if callable(sequence):
            print(sequence("Dragon", 5))
        else:
            raise Exception("Cannot call new spell_sequence")
    except Exception as e:
        print(f"Got error: {e}")


if __name__ == "__main__":
    main()
