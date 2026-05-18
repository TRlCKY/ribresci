from alchemy.grimoire.dark_validator import validate_ingredients


def dark_spell_allowed_ingredients() -> list[str]:
    return ["bats", "frogs", "arsenic", "eyeball"]


def dark_spell_record(spell_name: str, ingredients: str) -> str:
    valid = validate_ingredients(ingredients)
    if valid == "VALID":
        return f"Spell recorded: {spell_name} :{ingredients} - {valid}"
    elif valid == "INVALID":
        return "Invalid spell, can't be recorded"
    else:
        return "This was not supposed to happen..."
