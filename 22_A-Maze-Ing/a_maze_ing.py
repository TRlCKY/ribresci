from mazegenerator import MazeGenerator
from renderer import output_file, print_labyrinth
from mazegenerator import solver
from typing import Any


def reding_input(fd: str) -> dict[str, Any]:
    data: dict[str, Any] = {}
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


def menu() -> int:
    while True:
        print("Menu:")
        print("1) Re-generate a new maze")
        print("2) Show/Hide a valid shortest path")
        print("3) Change maze wall colours")
        print("4) Quit")
        try:
            x = int(input("Insert the number: "))
            if x >= 1 and x <= 4:
                return x
            else:
                print("Wrong number inserted")
        except Exception as e:
            print(f'Got error: {e}')


def choose_color() -> int:
    while True:
        print("Choose a color:")
        print("1) White")
        print("2) Magenta")
        print("3) Cyan")
        print("4) Quit")
        try:
            x = int(input("Insert the number: "))
            if x >= 1 and x <= 4:
                return x
            else:
                print("Wrong number inserted")
        except Exception as e:
            print(f'Got error: {e}')


if __name__ == "__main__":
    color = "\033[37m"
    hide = True
    data = reding_input("config/config.txt")
    maze = MazeGenerator(data)
    maze._init_grid()
    maze._prim_algorithm()
    solver.solve_maze(maze)
    print_labyrinth(maze, 0, color)
    output_file(maze)
    while True:
        print("=== A-Maze-Ing ===")
        num = menu()
        match num:
            case 1:
                data = reding_input("config/config.txt")
                print(data)
                maze = MazeGenerator(data)
                maze._init_grid()
                maze._prim_algorithm()
                solver.solve_maze(maze)
                hide = True
                print_labyrinth(maze, 0, color)
            case 2:
                if hide is True:
                    print_labyrinth(maze, 1, color)
                    hide = False
                else:
                    print_labyrinth(maze, 0, color)
                    hide = True
            case 3:
                col = choose_color()
                match col:
                    case 1:
                        color = "\033[37m"
                        print_labyrinth(maze, 0, color)
                    case 2:
                        color = "\033[35m"
                        print_labyrinth(maze, 0, color)
                    case 3:
                        color = "\033[36m"
                        print_labyrinth(maze, 0, color)
                    case 4:
                        print_labyrinth(maze, 0, color)
            case 4:
                exit()
            case _:
                print("Invalid number")
