from classes import Hub, Connection
import heapq


def sort_list(hub: Hub) -> int:
    if hub.type == "start":
        return 0
    elif hub.type == "end":
        return 2
    else:
        return 1


# def get_near_hubs(curr_hub: Hub, hub_list: list[Hub]) -> list[Hub]:
#     near_hubs: list[Hub] = []
#     for hub in hub_list:
#         for near in curr_hub.connected:
#             if ((near.hub0.name == hub.name or near.hub1.name == hub.name)
#                and hub.visited is False and hub.zone != 'blocked'):
#                 near_hubs.append(hub)
#     return near_hubs


def get_near_conn_hub(hub: Hub, connection: Connection) -> Hub:
    if connection.hub0.name == hub.name:
        return connection.hub1
    else:
        return connection.hub0


def solver(hub_list: list[Hub]) -> list[Hub]:
    # Ordina la lista mettendo start in cima e end in fondo alla lista
    hub_list.sort(key=sort_list)
    path: list[Hub] = []
    distances: dict[str, int] = {}
    curr_hub: Hub = hub_list[0]
    end_hub = hub_list[len(hub_list) - 1]
    for hub in hub_list:
        # Imposta a ogni hub come distanza 4 (quelle vere sono solo da 1 a 3)
        distances[hub.name] = 4
    # La distanza da start e' 0
    distances[curr_hub.name] = 0
    # Indica l'hub precedente
    parent: dict[str, Hub | None] = {}
    parent[curr_hub.name] = None
    # Distanza, Nome, Hub
    heap: list[tuple[int, str, Hub]] = []
    # Nell'heap viene inserito start che stara' sempre in cima essendo quello
    # con il valore piu' piccolo(sono ordinati in ordine crescente)
    heapq.heappush(heap, (0, curr_hub.name, curr_hub))
    while heap:
        el = heapq.heappop(heap)
        dist = el[0]
        hub0 = el[2]
        if dist > distances[hub.name]:
            continue
        if hub0.type == 'end':
            break
        for conn in hub.connected:
            next = get_near_conn_hub(hub0, conn)
            if next.zone == 'blocked':
                continue
            new_cost = dist + next.cost
            if new_cost < distances[next.name]:
                distances[next.name] = new_cost
                parent[next.name] = hub0
                heapq.heappush(heap, (new_cost, next.name, next))
    # Se non ci sono soluzioni, restituisce una lista vuota
    if end_hub.name not in parent:
        return []
    current_hub: Hub | None = end_hub
    while current_hub is not None:
        path.append(current_hub)
        current_hub = parent[current_hub.name]
    path.reverse()
    return path


# def update_path(prev_h: Hub, next_h: Hub) -> None:
#     new_path = prev_h.path
#     new_path.append(next_h)
#     next_h.path = new_path
