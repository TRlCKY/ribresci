from pydantic import BaseModel, Field, model_validator, ValidationError
from enum import Enum
from datetime import datetime


CHI = '\033[0;104m'
RHI = '\033[0;101m'
GHI = '\033[0;102m'
RB = '\033[1;31m'
RES = '\033[0m'
UW = '\033[4;37m'


class ContactError(Exception):
    def __init__(self, msg: str | None = None):
        self.msg = msg


class ContactType(Enum):
    radio = 'radio'
    visual = 'visual'
    physical = 'physical'
    telepathic = 'telepathic'


class AlienContact(BaseModel):
    contact_id: str = Field(min_length=5, max_length=15)
    timestamp: datetime
    location: str = Field(min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(ge=0.0, le=10.0)
    duration_minutes: int = Field(ge=1, le=1440)
    witness_count: int = Field(ge=1, le=100)
    message_received: str | None = Field(default=None, max_length=500)
    is_verified: bool = Field(default=False)

    def display_data(self):
        print(f"{CHI}ID:{RES} {UW}{self.contact_id}{RES}")
        print(f"{CHI}Type:{RES} {UW}{self.contact_type.name}{RES}")
        print(f"{CHI}Location:{RES} {UW}{self.location}{RES}")
        print(f"{CHI}Date:{RES} {self.duration_minutes}{RES}")
        print(f"{CHI}Signal:{RES} {UW}{self.signal_strength}/10.0{RES}")
        print(f"{CHI}Duration:{RES} {UW}{self.duration_minutes}m{RES}")
        print(f"{CHI}Witnesses:{RES} {UW}{self.witness_count}{RES}")
        if self.message_received:
            print(f"{CHI}Message:{RES} {UW}'{self.message_received}'{RES}")
        print(f"{CHI}Verified:{RES}", end=" ")
        if self.is_verified:
            print(f"{GHI}YES{RES}\n")
        else:
            print(f"{RHI}NO{RES}\n")

    @model_validator(mode='after')
    def validate(self):
        if not self.contact_id.startswith('AC'):
            raise ContactError("Contact ID does not begin with 'AC'.")

        elif (self.contact_type is ContactType.physical and
              self.is_verified is False):
            raise ContactError("'Physical' contacts must be verified.")

        elif (self.contact_type is ContactType.telepathic and
              self.witness_count <= 3):
            raise ContactError("'Telepathic' contacts require > 3 witnesses.")

        elif (self.signal_strength > 7.0 and
              self.message_received is None):
            raise ContactError("Strong signals (>7.0) must have messages.")

        return self


def register_contact(data: dict) -> AlienContact | None:
    try:
        con = AlienContact.model_validate(data)
    except ContactError as e:
        print(f"{RHI}CONTACT REGISTRATION FAILED{RES}")
        print(f"{RB}{e}{RES}")
        return None
    except ValidationError as e:
        print(f"{RHI}CONTACT REGISTRATION FAILED{RES}")
        err = e.errors()[0]
        print(f"{RB}{err['msg']}{RES}")
        return None
    print(f"{GHI}REGISTERED VALID CONTACT{RES}")
    con.display_data()
    return(con)


def main():
    con1_data = {
        'contact_id': 'AC001',
        'timestamp': '1984-04-12 12:25',
        'location': 'Anchorage, Alaska',
        'contact_type': 'radio',
        'signal_strength': 7.5,
        'duration_minutes': 45,
        'witness_count': 6,
        'message_received': '42',
        'is_verified': True
    }
    register_contact(con1_data)

    con2_data = {
        'contact_id': 'AC0069',
        'timestamp': '1225-12-25 12:25:12',
        'location': 'Rome, Italy',
        'contact_type': 'physical',
        'signal_strength': 8.0,
        'duration_minutes': 50,
        'witness_count': 2,
        'message_received': 'DAJE ROMA DAJEEEEE',
    }
    register_contact(con2_data)


if __name__ == "__main__":
    print()
    main()
    print()
