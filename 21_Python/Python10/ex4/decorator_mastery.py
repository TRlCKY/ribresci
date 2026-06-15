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
        string = func(*args, **kwargs)
        end = time.perf_counter()
        timer = end - start
        print(f"Spell completed in {timer:.3f} seconds")
        return string
    return function


def power_validator(min_power: int) -> Callable:
    def decorator(func: Callable) -> Callable:
        @wraps(func)
        def function(*args, **kwargs):
            if len(args) == 3:
                power = args[2]
            else:
                power = args[1]
            if power < min_power:
                return "Insufficient power for this spell"
            return func(*args, **kwargs)
        return function
    return decorator


def retry_spell(max_attempts: int) -> Callable:
    def decorator(func: Callable) -> Callable:
        @wraps(func)
        def function(*args, **kwargs):
            for attempt in range(1, max_attempts + 1):
                try:
                    return func(*args, **kwargs)
                except Exception:
                    if attempt < max_attempts:
                        print(f"Spell failed, retrying... (attempt {attempt}/{max_attempts})")
                    else:
                        return f"Spell casting failed after {max_attempts} attempts"
        return function
    return decorator


class MageGuild:
    @staticmethod
    def validate_mage_target(target: str) -> bool:
        if len(target) < 3:
            return False
        string = target.split(" ")
        for word in string:
            if not word.strip().isalpha():
                return False
        return True

    @power_validator(10)
    def cast_spell(self, spell_target: str, power: int) -> str:
        return f"Successfully cast {spell_target} with {power} power"


def main():
    print("=== Spell Timer ===")

    @spell_timer
    def timed_fireball(target: str, power: int):
        return fireball(target, power)

    print("Testing spel timer:")
    print(timed_fireball("Dragon", 5))
    print()
    print("=== Spell Validator ===")

    @power_validator(10)
    def validated_spell(target: str, power: int):
        return fireball(target, power)

    print("Testing power validator:")
    print("Minimum power = 10")
    print("Trying to cast a spell with power = 5")
    print(validated_spell("Dragon", 5))
    print("Trying to cast a spell with power = 15")
    print(validated_spell("Dragon", 15))
    print()
    print("=== Retry Spell ===")

    @retry_spell(3)
    def unstable():
        return ballfire()

    print("Testing an invalid spell 3 times:")
    print(unstable())
    print()

    @retry_spell(3)
    def stable():
        return fireball("Dragon", 10)

    print("Testing a valid function 3 times:")
    print(stable())
    print()
    print("=== Mage Guild ===")
    print("Creating 2 Mages:")
    m0 = MageGuild()
    m1 = MageGuild()
    print("Testing validate mage target:")
    print("Trying with 'ma':")
    print(m0.validate_mage_target("ma"))
    print("Trying with 'Mario':")
    print(m0.validate_mage_target("Mario"))
    print("Testing power validator with a mage guild:")
    print("Trying with a 'Lightning' spell with power = 15")
    print(m1.cast_spell("Lighning", 15))
    print("Trying with a 'Heal' spell with power = 5")
    print(m1.cast_spell("Heal", 5))


if __name__ == "__main__":
    main()
