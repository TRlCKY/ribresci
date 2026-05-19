from .generator import MazeGenerator
# bfs: esplora tutte le celle vicine di quella corrente prima di proseguire
# percorso(corretto), coda(celle non visitate)


# si inizia dalla cella di entrata e si mette nella queue, con visited = 1
# si mette nella queue tutte le celle adiacenti da visitare con un criterio
# (N, E, S, W)
def solve_maze(lib: MazeGenerator):
    # path(curr_y, curr_x, p_y, p_x)
    path = list()
    queue = list()
    start = lib.ENTRY.split(".")
    end = lib.EXIT.split(".")
    current = lib.grill[int(start[1])][int(start[0])]
    path.append((current['y'], current['x'], -1, -1))
    add_cell(lib, queue, current, path)
    while queue:
        current = queue.pop(0)
        if current['y'] == end[0] and current['x'] == end[1]:
            break
        if current['visited'] is False:
            current['visited'] = True
        add_cell(lib, queue, current, path)
    # path_reveal(path, end, start)
    print(path)


def add_cell(lib: MazeGenerator, queue: list, current: dict, path: list):
    # path(p_y, p_x, curr_y, curr_x)
    if current['N'] is False and lib.grill[current['y'] - 1][current['x']]['visited'] is False:
        queue.append(lib.grill[current['y'] - 1][current['x']])
        path.append((current['y'] - 1, current['x'], current['y'], current['x']))
    if current['E'] is False and lib.grill[current['y']][current['x'] + 1]['visited'] is False:
        queue.append(lib.grill[current['y']][current['x'] + 1])
        path.append((current['y'], current['x'] + 1, current['y'], current['x']))
    if current['S'] is False and lib.grill[current['y'] + 1][current['x']]['visited'] is False:
        queue.append(lib.grill[current['y'] + 1][current['x']])
        path.append((current['y'] + 1, current['x'], current['y'], current['x']))
    if current['W'] is False and lib.grill[current['y']][current['x'] - 1]['visited'] is False:
        queue.append(lib.grill[current['y']][current['x'] - 1])
        path.append((current['y'], current['x'] - 1, current['y'], current['x']))
