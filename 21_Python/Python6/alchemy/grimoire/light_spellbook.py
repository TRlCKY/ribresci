def light_spell_allowed_ingredients() -> list[str]:
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:
    import alchemy.grimoire.light_validator
    valid = alchemy.grimoire.light_validator.validate_ingredients(ingredients)
    if valid == "VALID":
        return f"Spell recorded: {spell_name} :{ingredients} - {valid}"
    elif valid == "INVALID":
        return "Invalid spell, can't be recorded"
    else:
        return "This was not supposed to happen..."
