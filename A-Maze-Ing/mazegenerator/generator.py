import random


class MazeGenerator():
    def __init__(self, DATA: dict):
        self.WIDTH = DATA['WIDTH']
        self.HEIGHT = DATA['HEIGHT']
        self.ENTRY = DATA['ENTRY']
        self.EXIT = DATA['EXIT']
        self.PERFECT = DATA['PERFECT']
        self.grill = []
        self.list_candidates = []

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

    def _prim_algorithm(self):
        coordinates = self.ENTRY.split(".")
        current_cell = self.grill[int(coordinates[1])][int(coordinates[0])]
        current_cell['visited'] = True
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
