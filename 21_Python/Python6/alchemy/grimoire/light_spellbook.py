def light_spell_allowed_ingredients() -> list[str]:
    return ["earth", "air", "fire", "water"]


def light_spell_record(spell_name: str, ingredients: str) -> str:
    from alchemy.grimoire.light_validator import validate_ingredients
    valid = validate_ingredients(ingredients)
    if valid == "VALID":
        return f"Spell recorded: {spell_name} :{ingredients} - {valid}"
    elif valid == "INVALID":
        return "Invalid spell, can't be recorded"
    else:
        return "This was not supposed to happen..."
