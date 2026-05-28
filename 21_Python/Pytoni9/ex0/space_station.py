from pydantic import BaseModel, Field, ValidationError
from datetime import datetime


CHI = '\033[0;104m'
RHI = '\033[0;101m'
GHI = '\033[0;102m'
RB = '\033[1;31m'
RES = '\033[0m'
UW = '\033[4;37m'


class SpaceStation(BaseModel):
    station_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=1, max_length=50)
    crew_size: int = Field(ge=1, le=20)
    power_level: float = Field(ge=0.0, le=100.0)
    oxygen_level: float = Field(ge=0.0, le=100.0)
    last_maintenance: datetime
    is_operational: bool = Field(default=True)
    notes: str | None = Field(default=None, max_length=200)

    def display_data(self):
        print(f"{CHI}ID:{RES} {UW}{self.station_id}{RES}")
        print(f"{CHI}Name:{RES} {UW}{self.name}{RES}")
        print(f"{CHI}Crew Size:{RES} {UW}{self.crew_size}{RES}")
        print(f"{CHI}Power Level:{RES} {UW}{self.power_level}%{RES}")
        print(f"{CHI}Oxygen Level:{RES} {UW}{self.oxygen_level}%{RES}")
        print(f"{CHI}Last Maintenance:{RES} {UW}{self.last_maintenance}{RES}")
        print(f"{CHI}Status:{RES} ", end="")
        if self.is_operational:
            print(f"{GHI}Operational{RES}")
        else:
            print(f"{RHI}Not Operational{RES}")
        if self.notes:
            print(f"{CHI}Notes:{RES} {UW}{self.notes}{RES}\n")


def register_station(data: dict) -> SpaceStation | None:
    try:
        ss = SpaceStation(**data)
    except ValidationError as e:
        print(f"{RHI}SPACE STATION REGISTRATION FAILED{RES}")
        err = e.errors()[0]
        print(f"{RB}{err['msg']}{RES}")
        return None
    print(f"{GHI}REGISTERED VALID SPACE STATION{RES}")
    ss.display_data()
    return(ss)


def main():
    print(f"{CHI}SPACE STATION DATA VALIDATION{RES}\n")
    ss1_data = {
        'station_id': 'SS001',
        'name': 'Everest Station',
        'crew_size': 5,
        'power_level': 53.4,
        'oxygen_level': 65,
        'last_maintenance': '2077-03-05 12:25',
        'is_operational': True,
        'notes': 'wao che belle palle'
    }
    register_station(ss1_data)
    ss2_data = {
        'station_id': 'SS002',
        'name': 'Kilimanjaro Station',
        'crew_size': 500,
        'power_level': 69.69,
        'oxygen_level': 69.69,
        'last_maintenance': '2012-12-12 12:12:12',
        'is_operational': False
    }
    register_station(ss2_data)


if __name__ == "__main__":
    print()
    main()
    print()
