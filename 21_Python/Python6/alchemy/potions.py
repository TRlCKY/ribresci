import elements
import alchemy.elements


def healing_potion() -> str:
    msg = f"Healing potion brewed with '[{elements.create_fire()}]' and " \
          f"'[{elements.create_water()}]"
    return msg


def strength_potion() -> str:
    msg = f"Strength potion brewed with '[{alchemy.elements.create_earth()}" \
          f"]' and '[{alchemy.elements.create_air()}]"
    return msg
