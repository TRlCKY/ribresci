from typing import Callable, Any
import functools


def spell_reducer(spells: list[int], operation: str) -> int:
    if len(spells) == 0:
        return 0
    tot = 0
    match operation:
        case "add":
            tot = functools.reduce(lambda add, x: x + add, spells)
        case "multiply":
            tot = functools.reduce(lambda mul, x: x * mul, spells)
        case "max":
            tot = max(spells)
        case "min":
            tot = min(spells)
        case _:
            raise Exception("Invalid operation")
    return tot


def partial_enchanter(base_enchantment: Callable) -> dict[str, Callable]:
    fire_en = functools.partial(base_enchantment, 50, "fire")
    water_en = functools.partial(base_enchantment, 50, "water")
    ice_en = functools.partial(base_enchantment, 50, "ice")
    return {"Fire": fire_en, "Water": water_en, "Ice": ice_en}


@functools.lru_cache(maxsize=None)
def memoized_fibonacci(n: int) -> int:
    if n < 2:
        return n
    return memoized_fibonacci(n - 1) + memoized_fibonacci(n - 2)


def spell_dispatcher() -> Callable[[Any], str]:
    @functools.singledispatch
    def function(x) -> str:
        return "Unknow spell type"

    @function.register(int)
    def _(x) -> str:
        return f"Damage spell: {x}"

    @function.register(str)
    def _(x) -> str:
        return f"Echantment: {x}"

    @function.register(list)
    def _(x) -> str:
        return f"Multicast: {len(x)} spells"
    return function


def main():
    print("=== Spell Reducer ===")
    try:
        spells = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
        print(f"Creating a list of spells: {spells}")
        print(f"Sum: {spell_reducer(spells, 'add')}")
        print(f"Product: {spell_reducer(spells, 'multiply')}")
        print(f"Max: {spell_reducer(spells, 'max')}")
        print(f"Min: {spell_reducer(spells, 'min')}")
        print(f"Unknown operator: {spell_reducer(spells, 'Unknown')}")
    except Exception as e:
        print(f"Got error: {e}")
    print()
    print("=== Partial Enchanter ===")
    print("Creating a base enchanter function")

    def base_enchanter(power: int, element: str, target: str) -> str:
        return (f"{target} has been hit with a {element} attack"
                f" and has a power of {power}")
    print("Getting 3 specialized version of this function:")
    print(base_enchanter(3, "Fire", "Goblin"))
    partial = partial_enchanter(base_enchanter)
    print("3 specialized functions:")
    print(f"Enchanter 1: {partial['Fire']('Goblin')}")
    print(f"Enchanter 2: {partial['Water']('Witch')}")
    print(f"Enchanter 3: {partial['Ice']('Demon')}")
    print()
    print("=== Memoized Fibonacci ===")
    print("Testing memoized Fibonacci:")
    print(f"Fibonacci number 0: {memoized_fibonacci(0)}")
    print(f"Fibonacci number 1: {memoized_fibonacci(1)}")
    print(f"Fibonacci number 10: {memoized_fibonacci(10)}")
    print(f"Fibonacci number 15: {memoized_fibonacci(15)}")
    print()
    print("=== Spell Dispatcher ===")
    try:
        print("Testing spell dispatcher:")
        dispatcher = spell_dispatcher()
        print(dispatcher(42))
        print(dispatcher("Fireball"))
        print(dispatcher([0, 1, 2]))
        print(dispatcher({"ciao": 20}))
    except Exception as e:
        print(f"Got error: {e}")


if __name__ == "__main__":
    main()
