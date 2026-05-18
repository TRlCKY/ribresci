if __name__ == "__main__":
    print("=== Kaboom 1 ===")
    print("Access to alchemy/grimoire/dark_spellbook.py directly")
    s = "Bobby"
    ing = ['fire', 'water', 'Air', 'mud']
    print("Test import now - THIS WILL RAISE AN UNCAUGHT EXCEPTION")
    import alchemy.grimoire.dark_spellbook
    print("Testing record light spell: "
          f"{alchemy.grimoire.dark_spellbook.dark_spell_record(s, ing)}")
