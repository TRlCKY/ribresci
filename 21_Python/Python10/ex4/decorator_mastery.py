from typing import Callable
from functools import wraps
import time


def fireball(target: str, power: int) -> str:
    time.sleep(2.5)
    return f"Fireball spell hits {target} with a power of {power}"


def ballfire() -> str:
    if 2 / 0 == 1:
        return "How did we get here?"
    else:
        return "Huh?"


def spell_timer(func: Callable) -> Callable:
    @wraps(func)
    def function(*args, **kwargs) -> str:
        print(f"Casting {func.__name__}...")
        start = time.perf_counter()
        string = func(*args)
        end = time.perf_counter()
        timer = end - start
        print(f"Spell completed in {timer:.3f} seconds")
        return f"Result: {string}"
    return function


def power_validator(min_power: int) -> Callable:
    @wraps(...)
    def function(power: int, func: Callable, target: str) -> str:
        if power >= min_power:
            return (func(target, power))
        else:
            return ("Insufficient power for this spell")
    return function


def retry_spell(max_attempts: int) -> Callable:
    def function(spell: Callable, *args, **kwargs) -> None:
        x = 0
        n = max_attempts
        max_att = max_attempts
        while max_att > 0:
            try:
                print(spell(*args))
                max_att = 0
            except Exception:
                print("Spell failed, retrying...")
                x += 1
                max_att -= 1
        if x == n:
            print("Failed completely to cast this spell")
    return function


class MageGuild:
    @staticmethod
    def validate_mage_name(name: str) -> bool:
        if len(name) < 3:
            return False
        string = name.split(" ")
        for word in string:
            if not word.strip().isalpha():
                return False
        return True

    def cast_spell(self, spell_name: str, power: int) -> str:
        power_valid = power_validator(10)
        if (power_valid(power, fireball, spell_name) !=
                power_valid(1, fireball, spell_name)):
            return f"Successfully cast {spell_name} with {power} power"
        else:
            return "Insufficient power for this spell"


def main():
    print("=== Spell Timer ===")
    timer = spell_timer(fireball)
    print("Testing spel timer:")
    print(timer("Dragon", 5))
    power = power_validator(10)
    print()
    print("Testing power validator:")
    print("Minimum power = 10")
    print("Trying to cast a spell with power = 5")
    print(power(5, fireball, "Dragon"))
    print("Trying to cast a spell with power = 15")
    print(power(15, fireball, "Dragon"))
    print()
    print("=== Retry Spell ===")
    retry = retry_spell(3)
    print("Testing an invalid spell 3 times:")
    retry(ballfire)
    print("Testing a valid function 3 times:")
    retry(fireball, "Dragon", 10)
    print()
    print("=== Mage Guild ===")
    print("Creating 2 Mages:")
    m0 = MageGuild()
    m1 = MageGuild()
    print("Testing validate mage name:")
    print("Trying with 'ma':")
    print(m0.validate_mage_name("ma"))
    print("Trying with 'Mario':")
    print(m0.validate_mage_name("Mario"))
    print("Testing power validator with a mage guild:")
    print("Trying with a 'Lightning' spell with power = 15")
    print(m1.cast_spell("Lighning", 15))
    print("Trying with a 'Heal' spell with power = 5")
    print(m1.cast_spell("Heal", 5))


if __name__ == "__main__":
    main()
