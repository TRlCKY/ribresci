import sys
from parser import parser, get_values
from classes import Drone, Hub, Connection  # ParsingException
from classes import init_hubs, init_drones, init_connections, get_connected
from solver import dijkstra, get_near_conn_hub
import pygame


def main() -> None:
    pygame.init()
    running = True
    while running:
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
        running = False
    pygame.quit()


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
    for drone in d_list:
        drone.current_hub = start_hub
        drone.visited.append(start_hub)
    while current_turn <= 10:  # Sostituire alla fine con True
        if check_drones(d_list) is True:
            break
        print(f"\nTurn {current_turn}:")
        # Inizio turno
        for drone in d_list:
            poss_hubs: list[Hub] = []
            # I droni che sono su end non fanno nulla
            if (drone.current_hub is not None
               and drone.current_hub.type == "end"):
                drone.status = "finish"
                continue
            if drone.status == "restricted":
                drone.status = "reach"
            else:
                # Si trovano gli hub raggiungibili
                for conn in drone.current_hub.connected:
                    hub1 = get_near_conn_hub(drone.current_hub, conn)
                    # Vengono considerati solo quelli non visitati
                    if hub1 not in drone.visited:
                        poss_hubs.append(hub1)
                best_dist = int(distances.get(drone.current_hub.name))
                best_hub: Hub | None = None
                if drone.current_hub not in drone.visited:
                    drone.visited.append(drone.current_hub)
                for poss in poss_hubs:
                    # Controlla se l'hub e la connessone sono liberi e viene
                    # scelto quello con costo minore e in caso di parita' si
                    # controlla se uno dei vari hub ha una priority
                    if has_room(drone.current_hub, poss, c_list):
                        if ((best_dist > distances.get(poss.name))
                            or (best_dist == distances.get(poss.name)
                                and poss.zone == "priority")):
                            best_dist = distances.get(poss.name)
                            # Alla fine del for il drone di turno sara' nel
                            # percorso disponibile piu' veloce
                            best_hub = poss
                if best_hub is not None:
                    update_connection(drone, drone.current_hub,
                                      best_hub, c_list)
            # Vengono aggiornate le posizioni dei droni i loro status
            # Se best_hub resta None, non ci sono movimenti disponibili
            if best_hub is None:
                drone.status = "wait"
            # Quando current_hub = None significa che arriva all'hub restricted
            elif drone.current_hub is None:
                drone.status = "reach"
                drone.current_hub = drone.next_hub
                if drone.prev_hub is not None:
                    drone.prev_hub.current_drones -= 1
                drone.current_hub.current_drones += 1
                if drone.prev_connection is not None:
                    drone.prev_connection.drones_inside -= 1
                drone.current_connection.drones_inside += 1
                drone.next_hub = None
            elif best_hub.zone == "restricted":
                drone.prev_hub = drone.current_hub
                drone.current_hub = None
                drone.next_hub = best_hub
                drone.current_connection.drones_inside += 1
                drone.status = "restricted"
            elif best_hub.zone == "normal" or best_hub.zone == "priority":
                drone.status = "reach"
                drone.prev_hub = drone.current_hub
                drone.current_hub = best_hub
                if drone.prev_hub is not None:
                    drone.prev_hub.current_drones -= 1
                drone.current_hub.current_drones += 1
                if drone.prev_connection is not None:
                    drone.prev_connection.drones_inside -= 1
                drone.current_connection.drones_inside += 1
            # Il drone compie un azione e stampa il suo status
            drone.print_status(drone.current_hub)
            if (drone.current_hub is not None
               and drone.current_hub.type == 'end'):
                drone.status = "finish"
                drone.current_connection.drones_inside -= 1
        current_turn += 1


def update_connection(drone: Drone, curr_hub: Hub, poss: Hub,
                      connections: list[Connection]) -> None:
    for conn in connections:
        if ((curr_hub == conn.hub0 and poss == conn.hub1) or
           (curr_hub == conn.hub1 and poss == conn.hub0)):
            drone.prev_connection = drone.current_connection
            drone.current_connection = conn


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
        if d.current_hub is not None and d.current_hub.type == "end":
            x += 1
    if x == len(d_list):
        return True
    return False


if __name__ == "__main__":
    main()
