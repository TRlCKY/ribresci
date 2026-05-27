from mazegenerator import MazeGenerator
from renderer import output_file, print_labyrinth
from mazegenerator import solver
from typing import Any
import random
import sys


def reding_input(fd: str) -> dict[str, Any]:
    data: dict[str, Any] = {}
    try:
        with open(fd, "r") as vault:
            x = 0
            for variable in vault:
                value = variable.split("=")
                try:
                    if value[0] == "WIDTH" or value[0] == "HEIGHT":
                        data.update({value[0]: int(value[1])})
                        x += 1
                    if value[0] == "ENTRY" or value[0] == "EXIT":
                        data.update({value[0]: str(value[1].replace(',',
                                                                    '.'))})
                        x += 1
                    if value[0] == "PERFECT":
                        data.update({value[0]: bool(int(value[1]))})
                        x += 1
                    if value[0] == "OUTPUT_FILE":
                        data.update({value[0]: str(value[1])})
                        x += 1
                except ValueError as e:
                    print(f"Got ValueError: {e}")
                    exit()
            if data['WIDTH'] * data['HEIGHT'] < 63:
                raise Exception("Maze's dimensions too small, need HEIGTH >= 7"
                                "and WIDTH >= 9")
            if data['ENTRY'] == data['EXIT']:
                raise Exception("ENTRY and EXIT shares same cell")
            dt = data['ENTRY'].split(".")
            if int(dt[0]) >= data['WIDTH'] or int(dt[1]) >= data['HEIGHT']:
                raise Exception("ENTRY coordinates are outside the maze")
            dt = data['EXIT'].split(".")
            if int(dt[0]) >= data['WIDTH'] or int(dt[1]) >= data['HEIGHT']:
                raise Exception("EXIT coordinates are outside the maze")
            if x != 6:
                raise Exception("Some data are missing or are wrong")
    except FileNotFoundError as e:
        print(f"File error: {e}")
        exit()
    except Exception as e:
        print(f"Got error: {e}")
        exit()
    return data


def menu() -> int:
    while True:
        print("Menu:")
        print("1) Re-generate a new maze")
        print("2) Show/Hide a valid shortest path")
        print("3) Change maze wall colours")
        print("4) Set/print the seed")
        print("5) Quit")
        try:
            x = int(input("Insert the number: "))
            if x >= 1 and x <= 5:
                return x
            else:
                print("Wrong number. Try again")
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
                print("Wrong number. Try again")
        except Exception as e:
            print(f'Got error: {e}')


if __name__ == "__main__":
    color = "\033[37m"
    hide = True
    file = "config/"
    if len(sys.argv) == 1:
        raise Exception("File Not Found!")
    if len(sys.argv) > 2:
        raise Exception("Too many arguments!")
    file += sys.argv[1]
    data = reding_input(file)
    seed = random.randint(1, 100000)
    maze = MazeGenerator(data, seed)
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
                seed = random.randint(1, 100000)
                maze = MazeGenerator(data, seed)
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
                        if hide is True:
                            print_labyrinth(maze, 1, color)
                            hide = False
                        else:
                            print_labyrinth(maze, 0, color)
                            hide = True
                    case 2:
                        color = "\033[35m"
                        if hide is True:
                            print_labyrinth(maze, 1, color)
                            hide = False
                        else:
                            print_labyrinth(maze, 0, color)
                            hide = True
                    case 3:
                        color = "\033[36m"
                        if hide is True:
                            print_labyrinth(maze, 1, color)
                            hide = False
                        else:
                            print_labyrinth(maze, 0, color)
                            hide = True
                    case 4:
                        if hide is True:
                            print_labyrinth(maze, 1, color)
                            hide = False
                        else:
                            print_labyrinth(maze, 0, color)
                            hide = True
            case 4:
                while True:
                    print("1) Set seed")
                    print("2) Print seed")
                    print("3) Back to the menu")
                    x = int(input("Insert the number: "))
                    if x >= 1 and x <= 3:
                        break
                    else:
                        print("Wrong number. Try again")
                match x:
                    case 1:
                        try:
                            seed = int(input("Insert the seed: "))
                            data = reding_input("config/config.txt")
                            maze = MazeGenerator(data, seed)
                            maze._init_grid()
                            maze._prim_algorithm()
                            solver.solve_maze(maze)
                            hide = True
                            print_labyrinth(maze, 0, color)
                        except TypeError as e:
                            print(f"Got error: {e}")
                    case 2:
                        print(f"Seed: {maze.seed}")
                    case 3:
                        print()
            case 5:
                exit()
            case _:
                print("Invalid number")
