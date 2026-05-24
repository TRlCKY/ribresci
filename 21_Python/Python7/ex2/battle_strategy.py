from abc import ABC, abstractmethod
from ex2.creatures import Creature, TransformCapability, HealCapability


class BattleStrategy(ABC):
    def __init__(self):
        self.name = ""

    @abstractmethod
    def is_valid(self, creature: Creature) -> bool:
        pass

    @abstractmethod
    def act(self, creature: Creature):
        pass


class NormalStrategy(BattleStrategy):
    def __init__(self):
        self.name = "Normal Strategy"

    def is_valid(self, creature: Creature) -> bool:
        if isinstance(creature, Creature):
            return True
        return False

    def act(self, creature: Creature):
        if self.is_valid(creature):
            print(creature.attack())
        else:
            raise Exception(f"{self.name} is invalid for {creature.name}")


class AggressiveStrategy(BattleStrategy):
    def __init__(self):
        self.name = "Aggressive Strategy"

    def is_valid(self, creature: Creature) -> bool:
        if isinstance(creature, TransformCapability):
            return True
        return False

    def act(self, creature: Creature):
        if self.is_valid(creature):
            print(creature.transform())
            print(creature.attack())
            print(creature.revert())
        else:
            raise Exception(f"{self.name} is invalid for {creature.name}")


class DefensiveStrategy(BattleStrategy):
    def __init__(self):
        self.name = "Defensive Strategy"

    def is_valid(self, creature: Creature) -> bool:
        if isinstance(creature, HealCapability):
            return True
        return False

    def act(self, creature: Creature):
        if self.is_valid(creature):
            print(creature.attack())
            print(creature.heal("itself"))
        else:
            raise Exception(f"{self.name} is invalid for {creature.name}")
