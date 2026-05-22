from .generator import MazeGenerator
from typing import Any
# bfs: esplora tutte le celle vicine di quella corrente prima di proseguire
# percorso(corretto), coda(celle non visitate)


# si inizia dalla cella di entrata e si mette nella queue, con visited = 1
# si mette nella queue tutte le celle adiacenti da visitare con un criterio
# (N, E, S, W)
def solve_maze(lib: MazeGenerator):
    # path(curr_y, curr_x, p_y, p_x)
    path = list()
    queue: list[Any] = []
    start = lib.ENTRY.split(".")
    end = lib.EXIT.split(".")
    start_cell = lib.grill[int(start[1])][int(start[0])]
    exit_cell = lib.grill[int(end[1])][int(end[0])]
    path.append((start_cell['y'], start_cell['x'], -1, -1))
    add_cell(lib, queue, start_cell, path)
    while queue:
        current = queue.pop(0)
        if current['y'] == end[0] and current['x'] == end[1]:
            break
        if current['visited'] is False:
            current['visited'] = True
        add_cell(lib, queue, current, path)
    path_reveal(path, exit_cell, start_cell, lib)


def add_cell(lib: MazeGenerator, queue: list, current: dict, path: list):
    # path(p_y, p_x, curr_y, curr_x)
    if (current['N'] is False and lib.grill[current['y'] - 1][current['x']]
            ['visited'] is False):
        queue.append(lib.grill[current['y'] - 1][current['x']])
        path.append((current['y'] - 1, current['x'],
                     current['y'], current['x']))
    if (current['E'] is False and lib.grill[current['y']][current['x'] + 1]
            ['visited'] is False):
        queue.append(lib.grill[current['y']][current['x'] + 1])
        path.append((current['y'], current['x'] + 1,
                     current['y'], current['x']))
    if (current['S'] is False and lib.grill[current['y'] + 1][current['x']]
            ['visited'] is False):
        queue.append(lib.grill[current['y'] + 1][current['x']])
        path.append((current['y'] + 1, current['x'],
                     current['y'], current['x']))
    if (current['W'] is False and lib.grill[current['y']][current['x'] - 1]
            ['visited'] is False):
        queue.append(lib.grill[current['y']][current['x'] - 1])
        path.append((current['y'], current['x'] - 1,
                     current['y'], current['x']))


def path_reveal(path: list, exit: dict, start: dict, lib: MazeGenerator):
    real_path = list()
    for element in path:
        if element[0] == exit['y'] and element[1] == exit['x']:
            path_init = element
            break
    real_path.append(path_init)
    i = 0
    while path[i]:
        curr_tuple = path[i]
        if path_init[2] == curr_tuple[0] and path_init[3] == curr_tuple[1]:
            path_init = curr_tuple
            real_path.append(curr_tuple)
            x = path.pop(i)
            i = 0
            lib.grill[curr_tuple[0]][curr_tuple[1]]['value'] = 1
            if x[2] == start['y'] and x[3] == start['x']:
                break
        else:
            i += 1
    print(real_path)
    i = len(real_path) - 1
    while i >= 0:
        element = real_path[i]
        # primo if: su, 2: giu, 3: sx, 4: dx
        if element[2] - element[0] > 0:
            lib.solution += "N"
        elif element[2] - element[0] < 0:
            lib.solution += "S"
        elif element[3] - element[1] > 0:
            lib.solution += "W"
        else:
            lib.solution += "E"
        i -= 1

# txt[::-1]
