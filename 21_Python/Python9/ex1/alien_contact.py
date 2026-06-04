from pydantic import BaseModel, Field, model_validator
from enum import Enum
from datetime import datetime


class ContactType(Enum):
    radio = "RADIO"
    visual = "VISUAL"
    physical = "PHYSICAL"
    telepathic = "TELEPATHIC"


class AlienContact(BaseModel):
    contact_id: str = Field(..., min_length=5, max_length=15)
    timestamp: datetime = Field(default_factory=datetime.utcnow)
    location: str = Field(..., min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(..., ge=0.0, le=10.0)
    duration_minutes: int = Field(..., ge=1, le=1440)
    witness_count: int = Field(..., ge=1, le=100)
    message_received: str | None = Field(default=None, max_length=500)
    is_verified: bool = False

    @model_validator(mode='after')
    def validate(self):
        if not self.contact_id.startswith("AC"):
            raise Exception("Contact ID must starts with 'AC'")
        if (self.contact_type == ContactType.physical and
                self.is_verified is False):
            raise Exception("Physical contact reports must be verified")
        if (self.contact_type == ContactType.telepathic and
                self.witness_count < 3):
            raise Exception("Telepathic contact requires at least 3 witnesses")
        if self.signal_strength > 7.0 and self.message_received is None:
            raise Exception("Strong signals (> 7.0) should include a message")
        return self


def main():
    print("Alien Contact Log Validation")
    print("======================================")
    try:
        print("Valid contact report:")
        ac1 = AlienContact(
            contact_id="AC_2024_001",
            contact_type="RADIO",
            location="Area 51, Nevada",
            signal_strength=8.5,
            duration_minutes=45,
            witness_count=5,
            message_received="Greetings from Zeta Reticuli",
            is_verified=True
        )
        print(f"ID: {ac1.contact_id}")
        print(f"Type: {ac1.contact_type}")
        print(f"Location: {ac1.location}")
        print(f"Signal: {ac1.signal_strength}/10")
        print(f"Duration: {ac1.duration_minutes}")
        print(f"Witnesses: {ac1.witness_count}")
        print(f"Message: {ac1.message_received}")
    except Exception as e:
        print(f"Got error: {e}")
    print()
    print("======================================")
    try:
        print("Invalid contact report:")
        ac2 = AlienContact(
            contact_id="AC_2024_001",
            contact_type="TELEPATHIC",
            location="Area 51, Nevada",
            signal_strength=8.5,
            duration_minutes=45,
            witness_count=1,
            message_received="Greetings from Zeta Reticuli"
        )
        print(f"ID: {ac2.contact_id}")
        print(f"Type: {ac2.contact_type}")
        print(f"Location: {ac2.location}")
        print(f"Signal: {ac2.signal_strength}/10")
        print(f"Duration: {ac2.duration_minutes}")
        print(f"Witnesses: {ac2.witness_count}")
        print(f"Message: {ac2.message_received}")
    except Exception as e:
        print(f"Got error: {e}")


if __name__ == "__main__":
    main()
