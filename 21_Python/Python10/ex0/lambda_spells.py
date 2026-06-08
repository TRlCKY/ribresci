# Authorized: map, filter, sorted, min, max, round, sum, len
def artifact_sorter(artifacts: list[dict]) -> list[dict]:
    new_list = list(sorted(artifacts, key=lambda x: x["power"]))
    return new_list


def power_filter(mages: list[dict], min_power: int) -> list[dict]:
    new_list = list(filter(lambda x: x["power"] >= min_power, mages))
    return new_list


def spell_transformer(spells: list[str]) -> list[str]:
    new_list = list(map(lambda x: "*" + x + "*", spells))
    return new_list


def mage_stats(mages: list[dict]) -> dict:
    return {
        "max_power": max(mages, key=lambda x: x["power"])["power"],
        "min_power": min(mages, key=lambda x: x["power"])["power"],
        "avg_power": round(sum(map(lambda x: x["power"], mages)) /
                           len(mages), 2)
    }


def main():
    print("=== Artifact Sorter ===")
    print("Creating artifact list")
    a0 = {"name": "Useless Rock", "power": 0, "type": "Less Rock"}
    a1 = {"name": "Useful Rock", "power": 10, "type": "More Rock"}
    a2 = {"name": "Mid Rock", "power": 5, "type": "Just Rock"}
    art_list = [a0, a1, a2]
    print("Unsorted artifact list:")
    for art in art_list:
        print(art)
    art_sorted_list = artifact_sorter(art_list)
    print("Sorted artifact list by power:")
    for art in art_sorted_list:
        print(art)
    print()
    print("=== Mage Filter ===")
    print("Creating mages")
    m0 = {"name": "Kai", "power": 8, "element": "Fire"}
    m1 = {"name": "Lloyd", "power": 10, "element": "Green"}
    m2 = {"name": "Jay", "power": 6, "element": "Lightning"}
    mage_list = [m0, m1, m2]
    print("Unfiltered mage list:")
    for mage in mage_list:
        print(mage)
    mage_sorted_list = power_filter(mage_list, 8)
    print("Filtered mage list by power:")
    for mage in mage_sorted_list:
        print(mage)
    print()
    print("=== Spell Transformer ===")
    print("Creating a spell list")
    spell_list = ["Fireball", "Thunderball", "GreenBall"]
    for spell in spell_list:
        print(spell)
    trans_spell_list = spell_transformer(spell_list)
    print("Spell trasformed:")
    for spell in trans_spell_list:
        print(spell)
    print()
    print("=== Mage Statistics ===")
    print("Calculating mage stats")
    mage_statistics = mage_stats(mage_list)
    print(f"Mage stats: {mage_statistics}")


if __name__ == "__main__":
    main()
