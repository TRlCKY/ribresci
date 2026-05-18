from mazegenerator import MazeGenerator
from renderer import output_file, print_labyrinth


def reding_input(fd: str) -> dict:
    data = {}
    with open(fd, "r") as vault:
        for variable in vault:
            value = variable.split("=")
            if value[0] == "WIDTH" or value[0] == "HEIGHT":
                data.update({value[0]: int(value[1])})
            if value[0] == "ENTRY" or value[0] == "EXIT":
                data.update({value[0]: str(value[1].replace(',', '.'))})
            if value[0] == "PERFECT":
                data.update({value[0]: bool(value[1])})
            if value[0] == "OUTPUT_FILE":
                data.update({value[0]: str(value[1])})
    return data


if __name__ == "__main__":
    data = reding_input("config/config.txt")
    print(data)
    maze = MazeGenerator(data)
    maze._init_grid()
    maze._prim_algorithm()
    print("")
    output_file(maze)
    print_labyrinth(maze)
