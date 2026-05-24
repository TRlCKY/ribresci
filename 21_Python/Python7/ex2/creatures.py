from abc import ABC, abstractmethod


class Creature(ABC):
    def __init__(self):
        self.name = ""
        self.type = ""

    @abstractmethod
    def attack(self):
        pass

    def describe(self) -> str:
        return f"{self.name}: {self.type} creature"


class Flameling(Creature):
    def __init__(self):
        self.name = "Flameling"
        self.type = "Fire"

    def attack(self):
        return f"{self.name} uses Ember!"


class Pyrodon(Creature):
    def __init__(self):
        self.name = "Pyrodon"
        self.type = "Fire/Flying"

    def attack(self):
        return f"{self.name} uses Flamethrower!"


class Aquabub(Creature):
    def __init__(self):
        super().__init__()
        self.name = "Aquabub"
        self.type = "Water"

    def attack(self):
        return f"{self.name} uses Water Gun!"


class Torragaon(Creature):
    def __init__(self):
        super().__init__()
        self.name = "Torragon"
        self.type = "Water"

    def attack(self):
        return f"{self.name} uses Hydro Pump!"


class CreatureFactory(ABC):
    @abstractmethod
    def create_base(self):
        pass

    @abstractmethod
    def create_evolved(self):
        pass


class FlameFactory(CreatureFactory):
    def create_base(self) -> Flameling:
        flame = Flameling()
        return flame

    def create_evolved(self) -> Pyrodon:
        pyro = Pyrodon()
        return pyro


class AquaFactory(CreatureFactory):
    def create_base(self) -> Aquabub:
        aqua = Aquabub()
        return aqua

    def create_evolved(self) -> Torragaon:
        torra = Torragaon()
        return torra


class HealCapability(ABC):
    @abstractmethod
    def heal(self, target: str):
        pass


class TransformCapability(ABC):
    @abstractmethod
    def transform(self):
        pass

    @abstractmethod
    def revert(self):
        pass


class Sproutling(Creature, HealCapability):
    def __init__(self):
        super().__init__()
        self.name = "Sproutling"
        self.type = "Grass"

    def attack(self):
        return f"{self.name} uses Vine Whip!"

    def heal(self, target: str):
        return f"{self.name} heals {target} for a small amount"


class Bloomelle(Creature, HealCapability):
    def __init__(self):
        super().__init__()
        self.name = "Bloomelle"
        self.type = "Grass/Fairy"

    def attack(self):
        return f"{self.name} uses Petal Dance!"

    def heal(self, target):
        return f"{self.name} heals {target} for a large amount"


class Shiftling(Creature, TransformCapability):
    def __init__(self):
        self.name = "Shiftling"
        self.type = "Normal"
        self.status = "Normal"

    def attack(self):
        if self.status == "Normal":
            return f"{self.name} attacks normally."
        else:
            return f"{self.name} performs a boosted strike!"

    def transform(self):
        self.status = "Transformed"
        return f"{self.name} shifts into a sharper form!"

    def revert(self):
        self.status = "Normal"
        return f"{self.name} returns to normal."


class Morphagon(Creature, TransformCapability):
    def __init__(self):
        self.name = "Morphagon"
        self.type = "Normal/Dragon"
        self.status = "Normal"

    def attack(self):
        if self.status == "Normal":
            return f"{self.name} attacks normally."
        else:
            return f"{self.name} unleashes a devastating morph strike!"

    def transform(self):
        self.status = "Transformed"
        return f"{self.name} morphs into a dragonic battle form!"

    def revert(self):
        self.status = "Normal"
        return f"{self.name} stabilizes its form."


class HealingCreatureFactory(CreatureFactory):
    def create_base(self) -> Sproutling:
        sprout = Sproutling()
        return sprout

    def create_evolved(self) -> Bloomelle:
        bloom = Bloomelle()
        return bloom


class TransformCreatureFactory(CreatureFactory):
    def create_base(self) -> Shiftling:
        shift = Shiftling()
        return shift

    def create_evolved(self) -> Morphagon:
        morph = Morphagon()
        return morph
