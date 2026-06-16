from .generator import MazeGenerator
from typing import Any, Dict, List, Tuple


def solve_maze(lib: MazeGenerator) -> None:
    path: List[Tuple[int, int, int, int]] = []
    queue: List[Dict[str, Any]] = []
    start = lib.ENTRY.split(".")
    end = lib.EXIT.split(".")
    start_cell: Dict[str, Any] = lib.grill[int(start[1])][int(start[0])]
    exit_cell: Dict[str, Any] = lib.grill[int(end[1])][int(end[0])]
    start_cell['value'] = 1
    exit_cell['value'] = 1
    path.append((start_cell['y'], start_cell['x'], -1, -1))
    add_cell(lib, queue, start_cell, path)
    while queue:
        current = queue.pop(0)
        if current['y'] == int(end[1]) and current['x'] == int(end[0]):
            break
        if current['visited'] is False:
            current['visited'] = True
        add_cell(lib, queue, current, path)
    path_reveal(path, exit_cell, start_cell, lib)


def add_cell(lib: MazeGenerator, queue: List[Dict[str, Any]],
             current: Dict[str, Any],
             path: List[Tuple[int, int, int, int]]) -> None:
    if (current['N'] is False
            and lib.grill[current['y'] - 1][current['x']]['visited'] is False):
        queue.append(lib.grill[current['y'] - 1][current['x']])
        path.append((current['y'] - 1, current['x'],
                     current['y'], current['x']))
    if (current['E'] is False
            and lib.grill[current['y']][current['x'] + 1]['visited'] is False):
        queue.append(lib.grill[current['y']][current['x'] + 1])
        path.append((current['y'], current['x'] + 1,
                     current['y'], current['x']))
    if (current['S'] is False
            and lib.grill[current['y'] + 1][current['x']]['visited'] is False):
        queue.append(lib.grill[current['y'] + 1][current['x']])
        path.append((current['y'] + 1, current['x'],
                     current['y'], current['x']))
    if (current['W'] is False
            and lib.grill[current['y']][current['x'] - 1]['visited'] is False):
        queue.append(lib.grill[current['y']][current['x'] - 1])
        path.append((current['y'], current['x'] - 1,
                     current['y'], current['x']))


def path_reveal(path: List[Tuple[int, int, int, int]], exit: Dict[str, Any],
                start: Dict[str, Any], lib: MazeGenerator) -> None:
    real_path: List[Tuple[int, int, int, int]] = []
    path_init: Tuple[int, int, int, int] = (0, 0, 0, 0)
    for element in path:
        if element[0] == exit['y'] and element[1] == exit['x']:
            path_init = element
            break
    real_path.append(path_init)
    i = 0
    while i < len(path):
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
    i = len(real_path) - 1
    while i >= 0:
        element = real_path[i]
        if element[2] - element[0] > 0:
            lib.solution += "N"
        elif element[2] - element[0] < 0:
            lib.solution += "S"
        elif element[3] - element[1] > 0:
            lib.solution += "W"
        else:
            lib.solution += "E"
        i -= 1
