from alchemy.grimoire.dark_spellbook import dark_spell_allowed_ingredients


def validate_ingredients(ingredients: str) -> str:
    list0 = dark_spell_allowed_ingredients()
    for element in list0:
        if element in ingredients:
            return "VALID"
    return "INVALID"
