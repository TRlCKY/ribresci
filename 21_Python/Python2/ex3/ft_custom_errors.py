class GardenError(Exception):
    def __init__(self, msg: str):
        super().__init__(msg)
        self.msg = "Unknow garden error"


class PlantError(GardenError):
    def __init__(self, msg: str):
        super().__init__(msg)
        self.msg = "The plant is not feeling very well:'("


class WaterError(GardenError):
    def __init__(self, msg: str):
        super().__init__(msg)
        self.msg = "Not enough H20 in the tank. Fill it bro."


def ft_custom_errors():
    print("=== Custom Garden Errors Demo ===")
    print()
    check_errors()
    print()
    show_errors()


def plant_errors(color: str):
    if color == "Brown":
        raise PlantError("Plant is dead. F")


def water_errors(litres: int):
    if litres < 0:
        raise WaterError("Water is negative. Wtf?")
    elif litres == 0:
        raise WaterError("No watha.")
    elif litres >= 30:
        raise WaterError("Hello I'm under the watha. Please help me.")


def check_errors():
    print("Testing PlantError...")
    try:
        plant_errors("Brown")
    except PlantError as e:
        print(f"Caught PlantError: {e}")
    print()
    print("Testing WaterError...")
    try:
        water_errors(-1)
    except WaterError as e:
        print(f"Caught WaterError: {e}")
    try:
        water_errors(0)
    except WaterError as e:
        print(f"Caught WaterError: {e}")
    try:
        water_errors(34)
    except WaterError as e:
        print(f"Caught WaterError: {e}")
    print()
    print("Testing catching all garden errors...")
    try:
        plant_errors("Brown")
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    try:
        water_errors(0)
    except GardenError as e:
        print(f"Caught GardenError: {e}")


def show_errors():
    print("All custom error types work correctly!")


if __name__ == "__main__":
    ft_custom_errors()
