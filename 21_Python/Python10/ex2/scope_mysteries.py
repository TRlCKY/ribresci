from typing import Callable
from typing import Any


def mage_counter() -> Callable:
    count = 0

    def function() -> int:
        nonlocal count
        count += 1
        return count
    return function


def spell_accumulator(initial_power: int) -> Callable:
    power0 = initial_power

    def function(num: int) -> int:
        nonlocal power0
        power0 += num
        return power0
    return function


def enchantment_factory(enchantment_type: str) -> Callable:
    enchantment0 = enchantment_type

    def function(item: str) -> str:
        nonlocal enchantment0
        enchantment0 += " " + item
        return enchantment0
    return function


def memory_vault() -> dict[str, Callable]:
    vault = {}

    def store(key: str, value: Any) -> str:
        nonlocal vault
        vault.update({key: value})
        return f"Stored {key} = {value}"

    def recall(key0: str) -> str:
        nonlocal vault
        return vault.get(key0, "Memory not found")
    return {"store": store, "recall": recall}


def main():
    print("=== Mage Counter ===")
    counter0 = mage_counter()
    counter1 = mage_counter()
    print("Calling function 5 times:")
    for i in range(5):
        print(f"Call number {i}: {counter0()}")
    print("Calling another function 3 times:")
    for i in range(3):
        print(f"Call number {i}: {counter1()}")
    print()
    print("=== Spell Accumulator ===")
    accumulator = spell_accumulator(100)
    print("Increasing power")
    print(f"Base 100, adding 20 = {accumulator(20)}")
    print(f"Base 100, adding 30 = {accumulator(30)}")
    print()
    print("=== Enchantment Factory ===")
    enchantment0 = enchantment_factory("Elemental")
    enchantment1 = enchantment_factory("Soul")
    print(f"Enchanting a scythe: {enchantment0('Schyte')}")
    print(f"Enchanting a dagger: {enchantment1('Dagger')}")
    print()
    print("=== Memory Vault ===")
    memory = memory_vault()
    print("Storing a 'secret' value 42:")
    print(memory["store"]("secret", 42))
    print("Recalling the 'secret' value:")
    print(memory["recall"]("secret"))
    print("Recalling an 'unknown' value who isn't inside the vault:")
    print(memory["recall"]("Unknow"))
    print()


if __name__ == "__main__":
    main()
