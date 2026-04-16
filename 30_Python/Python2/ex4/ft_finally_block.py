class GardenError(Exception):
    def __init__(self, msg: str):
        super().__init__(msg)
        self.msg = "Unknow garden error"


class WaterError(GardenError):
    def __init__(self, msg: str):
        super().__init__(msg)
        self.msg = "Not enough H20 in the tank. Fill it bro."
