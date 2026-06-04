
from pydantic import BaseModel, model_validator, Field, ValidationError
from enum import Enum
from datetime import datetime


CHI = '\033[0;104m'
RHI = '\033[0;101m'
GHI = '\033[0;102m'
RB = '\033[1;31m'
RES = '\033[0m'
UW = '\033[4;37m'


class MissionError(Exception):
    def __init__(self, msg: str | None = None):
        self.msg = msg


class Rank(Enum):
    cadet = 'cadet'
    officer = 'officer'
    lieutenant = 'lieutenant'
    captain = 'captain'
    commander = 'commander'


class CrewMember(BaseModel):
    member_id: str = Field(min_length=3, max_length=10)
    name: str = Field(min_length=2, max_length=50)
    rank: Rank
    age: int = Field(ge=18, le=80)
    specialization: str = Field(min_length=3, max_length=30)
    years_experience: int = Field(ge=0, le=50)
    is_active: bool = Field(default=True)

    def display(self):
        print(f"    -{UW}{self.name} ({self.rank.name}) - "
              f"{self.specialization}{RES}")


class SpaceMission(BaseModel):
    mission_id: str = Field(min_length=5, max_length=15)
    mission_name: str = Field(min_length=3, max_length=100)
    destination: str = Field(min_length=3, max_length=50)
    launch_date: datetime
    duration_days: int = Field(ge=1, le=3650)
    crew: list[CrewMember] = Field(min_length=1, max_length=12)
    mission_status: str = Field(default='planned')
    budget_millions: float = Field(ge=1.0, le=10000.0)

    def display(self):
        print(f"{CHI}ID:{RES} {UW}{self.mission_id}{RES}")
        print(f"{CHI}NAME:{RES} {UW}'{self.mission_name}'{RES}")
        print(f"{CHI}DESTINATION:{RES} {UW}{self.destination}{RES}")
        print(f"{CHI}LAUNCH DATE:{RES} {UW}{self.launch_date}{RES}")
        print(f"{CHI}DURATION:{RES} {UW}{self.duration_days} days{RES}")
        print(f"{CHI}CREW SIZE:{RES} {UW}{len(self.crew)}{RES}")
        print(f"{CHI}CREW MEMBERS:{RES}")
        for member in self.crew:
            member.display()
        print(f"{CHI}STATUS:{RES} {UW}{self.mission_status}{RES}\n")

    @model_validator(mode='after')
    def validate(self):
        if not self.mission_id.startswith('M'):
            raise MissionError("Mission ID must start with 'M'")

        rnk = False
        for member in self.crew:
            if (member.rank is Rank.commander or
                    member.rank is Rank.captain):
                rnk = True
        if rnk is False:
            raise MissionError("Mission must have a Commander/Captain")

        yr = True
        if self.duration_days > 365:
            for member in self.crew:
                if member.years_experience < 5:
                    yr = False
        if yr is False:
            raise MissionError("All members need >5 years of"
                               " experience for long (>365) missions.")

        act = True
        for member in self.crew:
            if not member.is_active:
                act = False
        if act is False:
            raise MissionError("All members must be active.")

        return self


def register_mission(data: dict) -> SpaceMission | None:
    try:
        mis = SpaceMission.model_validate(data)
    except MissionError as e:
        print(f"{RHI}MISSION REGISTRATION FAILED{RES}")
        print(f"{RB}{e}{RES}")
        return None
    except ValidationError as e:
        print(f"{RHI}MISSION REGISTRATION FAILED{RES}")
        err = e.errors()[0]
        print(f"{RB}{err['msg']}{RES}")
        return None
    print(f"{GHI}REGISTERED VALID MISSION{RES}")
    mis.display()
    return mis


def main():
    m1_data = {
        'mission_id': 'M2026_MOON',
        'mission_name': 'ARTEMIS 2',
        'destination': 'MOON',
        'launch_date': '2026-04-01 06:35',
        'duration_days': 9,
        'crew': [
            {
                'member_id': 'CM001',
                'name': 'Francesco Schettino',
                'rank': 'captain',
                'age': 50,
                'specialization': 'Mission Command',
                'years_experience': 19,
                'is_active': True
            },
            {
                'member_id': 'CM002',
                'name': 'Victor Glover',
                'rank': 'officer',
                'age': 50,
                'specialization': 'Pilot',
                'years_experience': 19,
                'is_active': True
            },
            {
                'member_id': 'CM003',
                'name': 'Christina Koch',
                'rank': 'officer',
                'age': 50,
                'specialization': 'Specialist 1',
                'years_experience': 15,
                'is_active': True
            },
            {
                'member_id': 'CM004',
                'name': 'Jeremy Hansen',
                'rank': 'officer',
                'age': 50,
                'specialization': 'Specialist 2',
                'years_experience': 13,
                'is_active': True
            },
        ],
        'mission_status': 'planned',
        'budget_millions': 2208.1
    }

    register_mission(m1_data)

    m2_data = {
        'mission_id': 'M2028_MUN',
        'mission_name': 'KERTEMIS',
        'destination': 'MUN',
        'launch_date': '2143-02-13 07:40',
        'duration_days': 412,
        'crew': [
            {
                'member_id': 'CM001',
                'name': 'Jebediah Kerman',
                'rank': 'captain',
                'age': 404,
                'specialization': 'Mission Command',
                'years_experience': 15,
                'is_active': True
            },
            {
                'member_id': 'CM002',
                'name': 'Valentina Kerman',
                'rank': 'officer',
                'age': 404,
                'specialization': 'Pilot',
                'years_experience': 15,
                'is_active': True
            },
            {
                'member_id': 'CM003',
                'name': 'Bill Kerman',
                'rank': 'officer',
                'age': 404,
                'specialization': 'Scientist',
                'years_experience': 15,
                'is_active': False
            },
        ],
        'mission_status': 'planned',
        'budget_millions': 5421.2
    }

    register_mission(m2_data)


if __name__ == "__main__":
    print()
    main()
    print()
