import random
from typing import Any, Dict, List, Tuple


class MazeGenerator:
    """
    MazeGenerator(size=(width, height), seed=None)

    Methods:
        generate() -> list[list[int]]
        get_solution() -> list[tuple[int, int]]
    """

    def __init__(self, DATA: Dict[str, Any], seed: int):
        self.WIDTH: int = int(DATA['WIDTH'])
        self.HEIGHT: int = int(DATA['HEIGHT'])
        self.ENTRY: str = str(DATA['ENTRY'])
        self.EXIT: str = str(DATA['EXIT'])
        self.OUTPUT_FILE: str = str(DATA['OUTPUT_FILE'])
        self.PERFECT: bool = bool(DATA['PERFECT'])
        self.seed: int = seed
        self.solution: str = ""
        self.grill: List[List[Dict[str, Any]]] = []
        self.list_candidates: List[Tuple[int, int, str]] = []

    def generate(self) -> List[List[Dict[str, Any]]]:
        self._init_grid()
        self._prim_algorithm()
        return self.grill

    def _init_grid(self) -> None:
        self.grill = [[{
            "N": True,
            "E": True,
            "S": True,
            "W": True,
            "value": 'F',
            "visited": False,
            "x": col,
            "y": row
        } for col in range(self.WIDTH)] for row in range(self.HEIGHT)]

    def _gen_42(self) -> None:
        middle: Dict[str, Any] = self.grill[self.HEIGHT // 2][self.WIDTH // 2]
        nw = self.grill[middle['y'] - 2][middle['x'] - 3]
        se = self.grill[middle['y'] + 2][middle['x'] + 3]
        nw['visited'] = True
        nw['value'] = 42
        se['visited'] = True
        se['value'] = 42
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

    def _prim_algorithm(self) -> None:
        random.seed(self.seed)
        self._gen_42()
        entry_coordinates = self.ENTRY.split(".")
        exit_coordinates = self.EXIT.split(".")
        try:
            current_cell = (self.grill[int(entry_coordinates[1])]
                            [int(entry_coordinates[0])])
            exit_cell = (self.grill[int(exit_coordinates[1])]
                         [int(exit_coordinates[0])])
        except ValueError as e:
            print(f"Got Error control Data file: {e}")
            exit()
        current_cell['visited'] = True
        try:
            if current_cell['value'] == 42 or exit_cell['value'] == 42:
                raise Exception("Entry or exit is inside 42")
        except Exception as e:
            print(f"Got error: {e}")
            exit()
        self._add_walls_of_cell(current_cell['x'], current_cell['y'])
        while self.list_candidates:
            muro = random.choice(self.list_candidates)
            x, y, direction = muro
            match direction:
                case 'N':
                    next_cell = self.grill[y - 1][x]
                case 'W':
                    next_cell = self.grill[y][x - 1]
                case 'S':
                    next_cell = self.grill[y + 1][x]
                case 'E':
                    next_cell = self.grill[y][x + 1]
                case _:
                    continue
            if not next_cell['visited'] and self.grill[y][x]['visited']:
                self._open_wall_between(self.grill[y][x], next_cell, direction)
                self._add_walls_of_cell(next_cell['x'], next_cell['y'])
            self.list_candidates.remove(muro)
        self.reset()
        if not self.PERFECT:
            self.make_imperfect(loops=int((self.WIDTH * self.HEIGHT) * 0.05))

    def _add_walls_of_cell(self, x: int, y: int) -> None:
        if (y > 0 and self.grill[y][x]['N']
                and not self.grill[y - 1][x]['visited']):
            self.list_candidates.append((x, y, "N"))
        if (y < self.HEIGHT - 1 and self.grill[y][x]['S']
                and not self.grill[y + 1][x]['visited']):
            self.list_candidates.append((x, y, "S"))
        if (x > 0 and self.grill[y][x]['W']
                and not self.grill[y][x - 1]['visited']):
            self.list_candidates.append((x, y, "W"))
        if (x < self.WIDTH - 1 and self.grill[y][x]['E']
                and not self.grill[y][x + 1]['visited']):
            self.list_candidates.append((x, y, "E"))

    def _open_wall_between(self, cellA: Dict[str, Any], cellB: Dict[str, Any],
                           muro: str) -> None:
        opposite = {'N': 'S', 'S': 'N', 'E': 'W', 'W': 'E'}
        cellA[muro] = False
        cellB[opposite[muro]] = False
        cellB['visited'] = True

    def reset(self) -> None:
        for row in self.grill:
            for current in row:
                if current['value'] != 42:
                    current['visited'] = False

    def make_imperfect(self, loops: int) -> None:
        for _ in range(loops):
            x = random.randint(0, self.WIDTH - 2)
            y = random.randint(0, self.HEIGHT - 2)
            cell = self.grill[y][x]
            neighbor = self.grill[y][x + 1]
            if cell["E"] and neighbor["W"]:
                cell["E"] = False
            neighbor["W"] = False
