# Import Relativo
from ..elements import create_air
# Import Assoluto
from elements import create_fire
from alchemy.potions import strength_potion


def lead_to_gold() -> str:
    msg = "Recipe transmuting Lead to Gold: brew " \
         f"'{create_air()}'" \
         f"and '{strength_potion()}' mixed with '" \
         f"{create_fire()}'"
    return msg
