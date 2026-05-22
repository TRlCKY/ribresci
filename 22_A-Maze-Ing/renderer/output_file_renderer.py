from mazegenerator.generator import MazeGenerator


def output_file(lib: MazeGenerator) -> None:
    if not lib:
        raise Exception("Error not exits labyrinth!")
    try:
        file = open("output_maze.txt", "w")
        for row in lib.grill:
            output = ""
            for cell in row:
                txt = (f"{str(int(cell['W']))}"
                       f"{str(int(cell['S']))}"
                       f"{str(int(cell['E']))}{str(int(cell['N']))}")
                if hex(int(txt, 2))[2:] >= 'a':
                    output += (hex(int(txt, 2))[2:]).upper()
                else:
                    output += hex(int(txt, 2))[2:]
            output += "\n"
            file.write(output)
        file.write("\n")
        file.write(f"{lib.ENTRY.replace(".", ",")}")
        file.write(f"{lib.EXIT.replace(".", ",")}")
        file.write(lib.solution)
    except FileNotFoundError as e:
        print(f"Error output not create {e}")


def print_labyrinth(lib: MazeGenerator, n: int, color: str) -> None:
    coordinates_entry = lib.ENTRY.split(".")
    coordinates_exit = lib.EXIT.split(".")
    for y in range(lib.HEIGHT):
        top = ""
        for x in range(lib.WIDTH):
            z = lib.grill[y][x]
            if z['value'] == 42:
                top += "\033[93m" + "███" + "\033[0m"
            elif z["value"] == 1 and z['N'] is False and \
                    lib.grill[y - 1][x]['value'] == 1 and n == 1:
                if lib.grill[y][x - 1]['value'] == 42:
                    top += ("\033[33m" + "█" + "\033[0m" +
                            "\033[34m" + "██" + "\033[0m")
                elif lib.grill[y - 1][x - 1]['value'] == 42:
                    top += ("\033[33m" + "█" + "\033[0m" +
                            "\033[34m" + "██" + "\033[0m")
                else:
                    top += (f"{color}" + "█" + "\033[0m"
                            + "\033[34m" + "██" + "\033[0m")
            else:
                if lib.grill[y - 1][x]['value'] == 42:
                    top += "\033[33m" + "███" + "\033[0m"
                elif lib.grill[y][x - 1]['value'] == 42:
                    top += "\033[33m" + "█" + "\033[0m" + \
                        (f"{color}" + "██" + "\033[0m"
                         if lib.grill[y][x]["N"] else "  ")
                elif lib.grill[y - 1][x - 1]['value'] == 42:
                    top += "\033[33m" + "█" + "\033[0m" + \
                        (f"{color}" + "██" + "\033[0m"
                         if lib.grill[y][x]["N"] else "  ")
                else:
                    top += f"{color}" + "█" "\033[0m" + (
                        f"{color}" + "██" + "\033[0m"
                        if lib.grill[y][x]["N"] else "  ")
        top += f"{color}" + "█" + "\033[0m"
        print(top)

        middle = ""
        for x in range(lib.WIDTH):
            z = lib.grill[y][x]
            if z["value"] == 1 and n == 1:
                # lato sx cella del percorso
                if lib.grill[y][x - 1]['value'] == 42:
                    middle += ("\033[33m" + "█" + "\033[0m")
                elif lib.grill[y][x - 1]['value'] == 1 and z['W'] is False:
                    middle += ("\033[34m" + "█" + "\033[0m")
                else:
                    middle += (f"{color}" + "█" + "\033[0m"
                               if lib.grill[y][x]["W"] else " ")
                middle += "\033[34m" + "██" + "\033[0m"
            elif z['value'] == 42:
                middle += "\033[93m" + "███" + "\033[0m"
            elif y == int(coordinates_entry[1]) and x == int(
                    coordinates_entry[0]):
                middle += (f"{color}" + "█" + "\033[0m"
                           if lib.grill[y][x]["W"] else " ")
                middle += "\033[32m" + "██" + "\033[0m"
            elif y == int(coordinates_exit[1]) and x == int(
                    coordinates_exit[0]):
                middle += (f"{color}" + "█" + "\033[0m"
                           if lib.grill[y][x]["W"] else " ")
                middle += "\033[31m" + "██" + "\033[0m"
            else:
                if lib.grill[y][x - 1]['value'] == 42:
                    middle += ("\033[33m" + "█" + "\033[0m")
                else:
                    middle += (f"{color}" + "█" + "\033[0m"
                               if lib.grill[y][x]["W"] else " ")
                middle += "  "
        middle += (f"{color}" + "█" + "\033[0m"
                   if lib.grill[y][lib.WIDTH-1]["E"] else " ")
        print(middle)

    bottom = ""
    for x in range(lib.WIDTH):
        bottom += f"{color}" + "█" + "\033[0m" + (
            f"{color}" + "██" + "\033[0m" if
            lib.grill[lib.HEIGHT-1][x]["S"] else "  ")
    bottom += f"{color}" + "█" + "\033[0m"
    print(bottom)
