from classes import Hub, Connection
import heapq


def get_near_conn_hub(hub: Hub, connection: Connection) -> Hub:
    if connection.hub0.name == hub.name:
        return connection.hub1
    else:
        return connection.hub0


def dijkstra(hub_list: list[Hub]) -> dict[str, int]:
    distances: dict[str, int] = {}
    end_hub: Hub | None = None
    for h in hub_list:
        # Imposta a ogni hub come distanza la piu' alta (sys.maxint) (si pensa)
        distances[h.name] = 1000000000
        if h.type == "end":
            end_hub = h
    if end_hub is None:
        return distances
    # La distanza da start e' 0
    distances[end_hub.name] = 0
    # Distanza, Nome, Hub
    heap: list[tuple[int, str, Hub]] = []
    # Nell'heap viene inserito start che stara' sempre in cima essendo quello
    # con il valore piu' piccolo(sono ordinati in ordine crescente)
    heapq.heappush(heap, (0, end_hub.name, end_hub))
    while heap:
        el = heapq.heappop(heap)
        dist = el[0]
        hub = el[2]
        if dist > distances[hub.name]:
            continue
        for conn in hub.connected:
            nxt = get_near_conn_hub(hub, conn)
            if nxt.zone == 'blocked':
                continue
            new_cost = dist + hub.cost
            if new_cost < distances[nxt.name]:
                distances[nxt.name] = new_cost
                heapq.heappush(heap, (new_cost, nxt.name, nxt))
    return distances
