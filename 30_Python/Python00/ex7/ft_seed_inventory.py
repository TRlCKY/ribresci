def ft_seed_inventory(seed: str, quantity: int, unit: str) -> None:
    if unit == "packets":
        print(f"{seed.capitalize()} seeds: {quantity} {unit} available")
    elif unit == "grams":
        print(f"{seed.capitalize()} seeds: {quantity} {unit} total")
    elif unit == "area":
        print(f"{seed.capitalize()} seeds: covers {quantity} square meters")
    else:
        print("Unknown unit type")


# ft_seed_inventory("tomato", 15, "packets")
# ft_seed_inventory("carrot", 8, "grams")
# ft_seed_inventory("lettuce", 12, "area")
# ft_seed_inventory("Void", 0, "Nothing")
