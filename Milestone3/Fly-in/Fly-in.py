import sys
from parser import parser, get_values
from classes import Drone, Hub, Connection  # ParsingException
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
    # print_info(hubs, drones, connections)

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
    # print()
    # print("PATH:")
    # for name in distances:
    #     print(name, distances[name])
    current_turn = 1
    finish = 0
    for drone in d_list:
        drone.current_hub = start_hub
        drone.prev_hub = start_hub
    while current_turn <= 20:
        if check_drones(d_list) is True:
            break
        print(f"Turn {current_turn}:")
        x = 0
        # Inizio turno
        for drone in d_list:
            poss_hubs: list[Hub] = []
            # I droni che sono su end non fanno nulla
            if drone.current_hub.type == "end":
                drone.status = "finish"
                x += 1
                continue
            if drone.status == "restricted":
                drone.status = "reach"
                drone.current_hub = drone.prev_hub
                best_hub = drone.next_hub
            else:
                # Si trovano gli hub raggiungibili
                for conn in drone.current_hub.connected:
                    hub1 = get_near_conn_hub(drone.current_hub, conn)
                    # Quelli gia' visitati non vengono considerati
                    if hub1 not in drone.visited:
                        poss_hubs.append(hub1)
                best_dist = int(distances.get(drone.prev_hub.name))
                best_hub: Hub | None = None
                drone.visited.append(drone.prev_hub)
                for poss in poss_hubs:
                    # Controlla se l'hub e la connessone sono liberi e viene
                    # scelto quello con costo minore
                    if has_room(drone.prev_hub, poss, c_list):
                        if best_dist > distances.get(poss.name):
                            best_dist = distances.get(poss.name)
                            # Alla fine del for il drone di turno sara' nel
                            # percorso disponibile piu' veloce
                            best_hub = poss
            if best_hub is None:
                drone.status = "wait"
            elif drone.current_hub.zone == "restricted":
                drone.prev_hub = drone.current_hub
                drone.current_hub = None
                drone.next_hub = poss
                drone.status = "restricted"
            elif (drone.current_hub.zone == "normal"
                  or drone.current_hub.zone == "priority"):
                drone.status = "reach"
                drone.prev_hub = drone.current_hub
                drone.current_hub = best_hub
            # Il drone compie un azione e stampa il suo status
            drone.print_status(drone.current_hub)
            if drone.status == "reach":
                drone.current_hub.current_drones += 1
                drone.prev_hub.current_drones -= 1
                for conn in c_list:
                    if ((drone.current_hub == conn.hub0 and
                        drone.prev_hub == conn.hub1) or
                        (drone.current_hub == conn.hub1 and
                       drone.prev_hub == conn.hub0)):
                        conn.drones_inside += 1
                for conn in c_list:
                    if ((drone.current_hub == conn.hub0 and
                        drone.prev_hub == conn.hub1) or
                        (drone.current_hub == conn.hub1 and
                       drone.prev_hub == conn.hub0)):
                        conn.drones_inside -= 1
            if drone.current_hub.type == 'end':
                drone.status = "finish"
        # if x == len(d_list):
        #     finish = 1
        current_turn += 1


def has_room(curr_hub: Hub, poss_hub: Hub,
             connectins: list[Connection]) -> bool:
    for conn in connectins:
        if ((curr_hub == conn.hub0 and poss_hub == conn.hub1) or
           (curr_hub == conn.hub1 and poss_hub == conn.hub0)):
            if (conn.drones_inside < conn.max_link_capacity
               and poss_hub.current_drones < poss_hub.max_drones):
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


def check_drones(d_list: list[Drone]) -> bool:
    x = 0
    for d in d_list:
        if d.current_hub.type == "end":
            x += 1
    if x == len(d_list):
        return True
    return False


if __name__ == "__main__":
    main()
