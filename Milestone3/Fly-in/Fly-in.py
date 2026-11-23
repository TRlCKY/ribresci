import sys
from parser import parser, get_values
from classes import Drone, Hub, Connection, ParsingException
from classes import init_hubs, init_drones, init_connections, get_connected
from solver import dijkstra, get_near_conn_hub


def main() -> None:
    argv = sys.argv
    # try:
    if len(argv) != 2:
        raise Exception("Number of arguments isn't 2. Wronge.")
    init_list = get_values(argv)
    parser(init_list, argv[1])
    hubs = init_hubs(init_list)
    drones = init_drones(init_list)
    connections = init_connections(init_list, hubs)
    get_connected(connections, hubs)
    print_info(hubs, drones, connections)

    start(drones, connections, hubs)
    # except ParsingException as e:
    #     print(f"Got parsing Exception: {e}")
    # except Exception as e:
    #     print(f"Got Exception: {e}")


def start(d_list: list[Drone], c_list: list[Connection],
          h_list: list[Hub]) -> None:
    distances: dict[str, int] = dijkstra(h_list)
    start_hub: Hub | None = None
    # Trova l'hub di partenza
    for h in h_list:
        if h.type == "start":
            start_hub = h
            break
    if start_hub is None:
        raise Exception("There's something wrong, I can feel it. No start hub "
                        "in hub list.")
    print()
    print("PATH:")
    for name in distances:
        print(name, distances[name])
    current_turn = 1
    finish = 0
    for drone in d_list:
        drone.current_hub = start_hub
    while not finish:
        print(f"Turn {current_turn}:")
        poss_hubs: list[Hub] = []
        x = 0
        # Inizio turno
        for drone in d_list:
            # I droni che sono su end non fanno nulla
            if drone.current_hub.type == "end":
                drone.status = "finish"
                x += 1
                continue
            if drone.status == "restricted":
                drone.status = "reach"
            # Si trovano gli hub raggiungibili
            for conn in drone.current_hub.connected:
                hub1 = get_near_conn_hub(drone.current_hub, conn)
                # Quelli gia' visitati non vengono considerati
                if hub1.name not in drone.visited:
                    poss_hubs.append(hub1)
            if poss_hubs is []:
                raise Exception("Huh?!")
            hub_name: str | None = None
            for poss in poss_hubs:
                # Controlla se l'hub e la connessone sono liberi e viene
                # scelto quello con costo minore
                if has_room(drone.current_hub, poss, c_list) is True:
                    if distances[hub_name] > distances[poss.name]:
                        hub_name = poss.name
                        if poss.zone == "restricted":
                            drone.status = "restricted"
                        if poss.zone == "normal" or poss.zone == "priority":
                            drone.status = "reach"
                        drone.current_hub = poss
            # Il drone compie un azione e stampa il suo status
            if hub_name is None:
                drone.status = "wait"
            drone.print_status(drone.current_hub)
        if x == len(d_list):
            finish = 1


def has_room(curr_hub: Hub, poss_hub: Hub,
             connectins: list[Connection]) -> bool:
    for conn in connectins:
        if ((curr_hub == conn.hub0 and poss_hub == conn.hub1) or
           (curr_hub == conn.hub1 and poss_hub == conn.hub0)):
            if conn.max_link_capacity > 0 and poss_hub.max_drones > 0:
                return True
    return False


def print_info(hubs: list[Hub], drones: list[Drone],
               connections: list[Connection]) -> None:
    print("=== HUB INFO ===")
    for hub in hubs:
        hub.show()
    print()
    print("=== DRONE INFO ===")
    for drone in drones:
        drone.show()
    print()
    print("=== CONNECTION INFO ===")
    for conn in connections:
        conn.show()
    print()


if __name__ == "__main__":
    main()
