import random
from typing import Any


class MazeGenerator():
    def __init__(self, DATA: dict):
        self.WIDTH = DATA['WIDTH']
        self.HEIGHT = DATA['HEIGHT']
        self.ENTRY = DATA['ENTRY']
        self.EXIT = DATA['EXIT']
        self.PERFECT = DATA['PERFECT']
        self.solution = ""
        self.grill: list[list[dict[str, Any]]] = []
        self.list_candidates: list[tuple] = []

    def generate(self):
        self._init_grid()
        self._prim_algorithm()
        return self.grill

    def _init_grid(self):
        self.grill = [[{
                        "N": True,
                        "E": True,
                        "S": True,
                        "W": True,
                        "value": 'F',
                        "visited": False,
                        "x": col,
                        "y": row
                        } for col in range(self.WIDTH)] for row in range(
                            self.HEIGHT)]

    def _gen_42(self):
        middle = self.grill[int(self.HEIGHT / 2)][int(self.WIDTH / 2)]
        nw = self.grill[middle['y'] - 2][middle['x'] - 3]
        # ne = self.grill[middle['y'] - 2][middle['x'] + 3]
        # sw = self.grill[middle['y'] + 2][middle['x'] - 3]
        se = self.grill[middle['y'] + 2][middle['x'] + 3]
        nw['visited'] = True
        nw['value'] = 42
        # ne['visited'] = True
        se['visited'] = True
        se['value'] = 42
        # sw['visited'] = True
        # Crea il 4
        current_cell = self.grill[nw['y'] + 1][nw['x']]
        current_cell['visited'] = True
        current_cell['value'] = 42
        current_cell = self.grill[current_cell['y'] + 1][current_cell['x']]
        current_cell['visited'] = True
        current_cell['value'] = 42
        current_cell = self.grill[current_cell['y']][current_cell['x'] + 1]
        current_cell['visited'] = True
        current_cell['value'] = 42
        current_cell = self.grill[current_cell['y']][current_cell['x'] + 1]
        current_cell['visited'] = True
        current_cell['value'] = 42
        current_cell = self.grill[current_cell['y'] + 1][current_cell['x']]
        current_cell['visited'] = True
        current_cell['value'] = 42
        current_cell = self.grill[current_cell['y'] + 1][current_cell['x']]
        current_cell['visited'] = True
        current_cell['value'] = 42
        # Crea il 2
        current_cell = self.grill[se['y']][se['x'] - 1]
        current_cell['visited'] = True
        current_cell['value'] = 42
        current_cell = self.grill[current_cell['y']][current_cell['x'] - 1]
        current_cell['visited'] = True
        current_cell['value'] = 42
        current_cell = self.grill[current_cell['y'] - 1][current_cell['x']]
        current_cell['visited'] = True
        current_cell['value'] = 42
        current_cell = self.grill[current_cell['y'] - 1][current_cell['x']]
        current_cell['visited'] = True
        current_cell['value'] = 42
        current_cell = self.grill[current_cell['y']][current_cell['x'] + 1]
        current_cell['visited'] = True
        current_cell['value'] = 42
        current_cell = self.grill[current_cell['y']][current_cell['x'] + 1]
        current_cell['visited'] = True
        current_cell['value'] = 42
        current_cell = self.grill[current_cell['y'] - 1][current_cell['x']]
        current_cell['visited'] = True
        current_cell['value'] = 42
        current_cell = self.grill[current_cell['y'] - 1][current_cell['x']]
        current_cell['visited'] = True
        current_cell['value'] = 42
        current_cell = self.grill[current_cell['y']][current_cell['x'] - 1]
        current_cell['visited'] = True
        current_cell['value'] = 42
        current_cell = self.grill[current_cell['y']][current_cell['x'] - 1]
        current_cell['visited'] = True
        current_cell['value'] = 42

    def _prim_algorithm(self):
        self._gen_42()
        entry_coordinates = self.ENTRY.split(".")
        exit_coordinates = self.EXIT.split(".")
        current_cell = (self.grill[int(entry_coordinates[1])]
                        [int(entry_coordinates[0])])
        exit_cell = (self.grill[int(exit_coordinates[1])]
                     [int(exit_coordinates[0])])
        current_cell['visited'] = True
        if current_cell['value'] == 42 or exit_cell == 42:
            raise Exception("Entry or exit is inside 42")
        self._add_walls_of_cell(current_cell['x'], current_cell['y'])
        while self.list_candidates:
            muro = random.choice(self.list_candidates)
            match muro[2]:
                case 'N':
                    next_cell = self.grill[muro[1]-1][muro[0]]
                    if (next_cell['visited'] is False and
                            self.grill[muro[1]][muro[0]]['visited'] is True):
                        self._open_wall_between(self.grill[muro[1]][muro[0]],
                                                next_cell, 'N')
                        self._add_walls_of_cell(next_cell['x'], next_cell['y'])
                        self.list_candidates.remove(muro)
                    else:
                        self.list_candidates.remove(muro)
                case 'W':
                    next_cell = self.grill[muro[1]][muro[0]-1]
                    if (next_cell['visited'] is False and
                            self.grill[muro[1]][muro[0]]['visited'] is True):
                        self._open_wall_between(self.grill[muro[1]][muro[0]],
                                                next_cell, 'W')
                        self._add_walls_of_cell(next_cell['x'], next_cell['y'])
                        self.list_candidates.remove(muro)
                    else:
                        self.list_candidates.remove(muro)
                case 'S':
                    next_cell = self.grill[muro[1]+1][muro[0]]
                    if (next_cell['visited'] is False and
                            self.grill[muro[1]][muro[0]]['visited'] is True):
                        self._open_wall_between(self.grill[muro[1]][muro[0]],
                                                next_cell, 'S')
                        self._add_walls_of_cell(next_cell['x'], next_cell['y'])
                        self.list_candidates.remove(muro)
                    else:
                        self.list_candidates.remove(muro)
                case 'E':
                    next_cell = self.grill[muro[1]][muro[0]+1]
                    if (next_cell['visited'] is False and
                            self.grill[muro[1]][muro[0]]['visited'] is True):
                        self._open_wall_between(self.grill[muro[1]][muro[0]],
                                                next_cell, 'E')
                        self._add_walls_of_cell(next_cell['x'], next_cell['y'])
                        self.list_candidates.remove(muro)
                    else:
                        self.list_candidates.remove(muro)
        self.reset()

    def _add_walls_of_cell(self, x, y):
        if (y > 0 and self.grill[y][x]['N'] and
                not self.grill[y-1][x]['visited']):
            self.list_candidates.append((x, y, "N"))
        if (y < self.HEIGHT - 1 and self.grill[y][x]['S'] and
                not self.grill[y+1][x]['visited']):
            self.list_candidates.append((x, y, "S"))
        if (x > 0 and self.grill[y][x]['W'] and
                not self.grill[y][x-1]['visited']):
            self.list_candidates.append((x, y, "W"))
        if (x < self.WIDTH - 1 and self.grill[y][x]['E'] and
                not self.grill[y][x+1]['visited']):
            self.list_candidates.append((x, y, "E"))

    def _open_wall_between(self, cellA, cellB, muro):
        match muro:
            case 'N':
                opposite_wall = 'S'
            case 'S':
                opposite_wall = 'N'
            case 'E':
                opposite_wall = 'W'
            case 'W':
                opposite_wall = 'E'
        cellA[muro] = False
        cellB[opposite_wall] = False
        cellB['visited'] = True

    def reset(self):
        i = 0
        e = 0
        while i < self.WIDTH:
            e = 0
            while e < self.HEIGHT:
                current = self.grill[e][i]
                if current['value'] != 42:
                    current['visited'] = False
                e += 1
            i += 1
