def validate_ingredients(ingredients: str) -> str:
    from dark_spellbook import dark_spell_allowed_ingredients
    list0 = dark_spell_allowed_ingredients()
    for element in list0:
        if ingredients.find(element):
            return "VALID"
    return "INVALID"
