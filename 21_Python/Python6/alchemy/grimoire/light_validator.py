def validate_ingredients(ingredients: str) -> str:
    from alchemy.grimoire.light_spellbook \
     import light_spell_allowed_ingredients
    list0 = light_spell_allowed_ingredients()
    for element in list0:
        if ingredients.find(element):
            return "VALID"
    return "INVALID"
