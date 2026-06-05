from enum import Enum
from pydantic import BaseModel, Field, model_validator
from datetime import datetime


class Rank(Enum):
    cadet = "CADET"
    officer = "OFFICER"
    lieutenant = "LIEUTENANT"
    captain = "CAPTAIN"
    commander = "COMMANDER"


class CrewMember(BaseModel):
    member_id: str = Field(..., min_length=3, max_length=10)
    name: str = Field(..., min_length=2, max_length=50)
    rank: Rank
    age: int = Field(..., ge=18, le=80)
    specialization: str = Field(..., min_length=3, max_length=30)
    years_experience: int = Field(..., ge=0, le=50)
    is_active: bool = True


class SpaceMission(BaseModel):
    mission_id: str = Field(..., min_length=5, max_length=15)
    mission_name: str = Field(..., min_length=3, max_length=100)
    destination: str = Field(..., min_length=3, max_length=50)
    launch_date: datetime = Field(default_factory=datetime.utcnow)
    duration_days: int = Field(..., ge=1, le=3650)
    crew: list[CrewMember] = Field(..., min_length=1, max_length=12)
    mission_status: str = Field(default="Planned")
    budget_millions: float = Field(..., ge=1.0, le=10000.0)

    @model_validator(mode="after")
    def validate(self):
        x = 0
        exp = 0
        num_crew = len(self.crew)
        if not self.mission_id.startswith("M"):
            raise Exception("Mission ID must start with 'M'")
        for member in self.crew:
            if (member.rank.value == "CAPTAIN"
                    or member.rank.value == "COMMANDER"):
                x += 1
        if x == 0:
            raise Exception("Mission must have at least one Commander"
                            " or Captain")
        if self.duration_days > 365:
            for member in self.crew:
                if member.years_experience >= 5:
                    exp += 1
        if exp < num_crew / 2:
            raise Exception("Long missions (> 365 days) need 50% experienced"
                            " crew (5+ years)")
        for member in self.crew:
            if member.is_active is False:
                raise Exception("All crew members must be active")
        return self


def main():
    print("Space Mission Crew Validation")
    try:
        print("Creating crew members")
        crew0 = CrewMember(
            member_id="C00",
            name="Cicciogamer89",
            rank="CAPTAIN",
            age=37,
            specialization="Hamburger and Barber Shop",
            years_experience=30,
            is_active=True
        )
        crew1 = CrewMember(
            member_id="C01",
            name="Grax",
            rank="COMMANDER",
            age=25,
            specialization="Hog Raider",
            years_experience=25,
            is_active=True
        )
        crew2 = CrewMember(
            member_id="C02",
            name="Poldo",
            rank="CADET",
            age=24,
            specialization="Minecraft",
            years_experience=43,
            is_active=True
        )
    except Exception as e:
        print(f"Got error: {e}")
        exit()
    crew_list = [crew0, crew1, crew2]
    print("=========================================")
    try:
        print("Valid mission created:")
        sm1 = SpaceMission(
            mission_name="Mars Colony Establishment",
            mission_id="M2024_MARS",
            destination="Mars",
            duration_days=900,
            budget_millions=2500.0,
            crew=crew_list
        )
        print(f"Mission: {sm1.mission_name}")
        print(f"ID: {sm1.mission_id}")
        print(f"Destination: {sm1.destination}")
        print(f"Duration: {sm1.duration_days} days")
        print(f"Budget: {sm1.budget_millions}M")
        print(f"Crew size: {len(sm1.crew)}")
        for member in sm1.crew:
            print(f"- {member.name} ({member.rank.value}) - "
                  f"{member.specialization}")
    except Exception as e:
        print(f"Got error: {e}")
    print("=========================================")
    try:
        print("Invalid mission created:")
        sm2 = SpaceMission(
            mission_name="Mars Colony Establishment",
            mission_id="INVALID",
            destination="Mars",
            duration_days=900,
            budget_millions=2500.0,
            crew=crew_list
        )
        print(f"Mission: {sm2.mission_name}")
        print(f"ID: {sm2.mission_id}")
        print(f"Destination: {sm2.destination}")
        print(f"Duration: {sm2.duration_days} days")
        print(f"Budget: {sm2.budget_millions}M")
        print(f"Crew size: {len(sm2.crew)}")
        for member in sm2.crew:
            print(f"- {member.name} ({member.rank}) - {member.specialization}")
    except Exception as e:
        print(f"Got error: {e}")


if __name__ == "__main__":
    main()
