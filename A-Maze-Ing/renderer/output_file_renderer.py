from mazegenerator.generator import MazeGenerator


def output_file(lib: MazeGenerator) -> None:
    if not lib:
        raise ("Error not exits labyrinth!")
    try:
        file = open("renderer/data.txt", "w")
        for row in lib.grill:
            for cell in row:
                txt = (f"{cell['x']},{cell['y']},{str(int(cell['N']))},"
                       f"{str(int(cell['E']))},"
                       f"{str(int(cell['S']))},{str(int(cell['W']))}\n")
                file.write(txt)
    except FileNotFoundError as e:
        print(f"Error file not create {e}")


def print_labyrinth(lib: MazeGenerator) -> None:
    coordinates_entry = lib.ENTRY.split(".")
    coordinates_exit = lib.EXIT.split(".")
    for y in range(lib.HEIGHT):
        top = ""
        for x in range(lib.WIDTH):
            top += "█" + ("███" if lib.grill[y][x]["N"] else "   ")
        top += "█"
        print(top)

        middle = ""
        for x in range(lib.WIDTH):
            if y == int(coordinates_entry[1]) and x == int(
                    coordinates_entry[0]):
                middle += ("█" if lib.grill[y][x]["W"] else " ")
                middle += "\033[31m" + "███" + "\033[0m"
            elif y == int(coordinates_exit[1]) and x == int(
                    coordinates_exit[0]):
                middle += ("█" if lib.grill[y][x]["W"] else " ")
                middle += "\033[32m" + "███" + "\033[0m"
            else:
                middle += ("█" if lib.grill[y][x]["W"] else " ")
                middle += "   "
        middle += "█" if lib.grill[y][lib.WIDTH-1]["E"] else " "
        print(middle)

    bottom = ""
    for x in range(lib.WIDTH):
        bottom += "█" + ("███" if lib.grill[lib.HEIGHT-1][x]["S"] else "   ")
    bottom += "█"
    print(bottom)

