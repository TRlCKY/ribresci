import alchemy.grimoire


if __name__ == "__main__":
    print("=== Kaboom 0 ===")
    print("Using grimoire module directly")
    name = "Bobby"
    ing = "'fire', 'water', 'Air', 'mud'"
    print("Testing record light spell: "
          f"{alchemy.grimoire.light_spell_record(name, ing)}")
