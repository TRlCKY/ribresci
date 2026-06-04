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
    crew: list[CrewMember] = Field(..., ge=1, le=12)
    mission_status: str = Field(..., default="Planned")
    budget_millions: float = Field(..., ge=1.0, le=10000.0)

    @model_validator(mode="after")
    def validate(self):
        x = 0
        exp = 0
        num_crew = len(self.crew)
        if not self.mission_id.startswith("M"):
            raise Exception("Mission ID must start with 'M'")
        for member in self.crew:
            if member.rank == "CAPTAIN" or member.rank == "COMMANDER":
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
    print()


if __name__ == "__main__":
    main()
