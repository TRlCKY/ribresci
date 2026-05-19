from abc import ABC, abstractmethod


class Creature(ABC):
    def __init__(self):
        self.name = ""
        self.type = ""

    @abstractmethod
    def attack(self):
        pass

    def describe(self):
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
