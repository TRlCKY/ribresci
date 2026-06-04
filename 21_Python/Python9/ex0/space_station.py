from pydantic import BaseModel, Field
from datetime import datetime


class SpaceStation(BaseModel):
    station_id: str = Field(..., min_length=3, max_length=10)
    name: str = Field(..., min_length=1, max_length=50)
    crew_size: int = Field(..., ge=1, le=20)
    power_level: float = Field(..., ge=0.0, le=100.0)
    oxygen_level: float = Field(..., ge=0.0, le=100.0)
    last_maintenance: datetime = Field(default_factory=datetime.utcnow)
    is_operational: bool = True
    notes: str | None = Field(default=None, max_length=200)


def main():
    print("Space Station Data Validation")
    print("========================================")
    try:
        print("Creating a valid spaceship")
        s1 = SpaceStation(
            station_id="ISS001",
            name="Valid Space Station",
            crew_size=6,
            power_level=85.5,
            oxygen_level=92.3)
    except Exception as e:
        print(f"Got error: {e}")
    print("Valid station created:")
    print(f"ID: {s1.station_id}")
    print(f"Name: {s1.name}")
    print(f"Crew: {s1.crew_size} people")
    print(f"Power: {s1.power_level}%")
    print(f"Oxygen: {s1.oxygen_level}%")
    print(f"Last maintenance: {s1.last_maintenance.strftime('%Y-%m-%d')}")
    if s1.is_operational is True:
        print("Status: Opearational")
    else:
        print("Status: Not Opearational")
    print()
    print("========================================")
    try:
        print("Creating an invalid spaceship")
        s2 = SpaceStation(
            station_id="ISS001",
            name="Invalid Space Station",
            crew_size=23,
            power_level=85.5,
            oxygen_level=92.3)
        print("Valid station created:")
        print(f"ID: {s2.station_id}")
        print(f"Name: {s2.name}")
        print(f"Crew: {s2.crew_size} people")
        print(f"Power: {s2.power_level}%")
        print(f"Oxygen: {s2.oxygen_level}%")
        print(f"Last maintenance: {s2.last_maintenance}")
        if s2.is_operational is True:
            print("Status: Opearational")
        else:
            print("Status: Not Opearational")
    except Exception as e:
        print(f"Got error: {e}")


if __name__ == "__main__":
    main()
