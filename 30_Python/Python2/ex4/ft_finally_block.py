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


def water_plant(plant_name: str):
    if plant_name == plant_name.capitalize():
        print(f"Watering {plant_name}: [OK]")
    else:
        raise PlantError(f"Water can't be planted because its name "
                         f"is {plant_name} and not {plant_name.capitalize()}")


def test_watering_system():
    try:
        print("Testing valid plants...")
        print("Open watering system")
        water_plant("Tomato")
        water_plant("Lettuce")
        water_plant("Carrots")
        print("Closing watering system")
        print()
        print("Testing invalid plants...")
        print("Open watering system")
        water_plant("tomato")
        water_plant("lettuce")
        water_plant("carrots")
        print("Closing watering system")
        print()
    except PlantError as e:
        print(f"Caught PlantError: Invalid plant name to water: {e}")
        print(".. ending tests and returning to main")
        print("Closing watering system")
    finally:
        print()
        print("Cleanup always happens, even with errors!")


def ft_finally_block():
    print("=== Garden Watering System ===")
    print()
    test_watering_system()


if __name__ == "__main__":
    ft_finally_block()
