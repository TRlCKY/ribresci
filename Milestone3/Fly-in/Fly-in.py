import sys
from parser import parser, get_values, ParsingException
from classes import init_hubs, init_drones, init_connections, get_connected
from classes import Drone, Hub, Connection
from solver import solver


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
    get_connected(init_list, hubs)
    print_info(hubs, drones, connections)

    start(drones, connections, hubs)
    # except ParsingException as e:
    #     print(f"Got parsing Exception: {e}")
    # except Exception as e:
    #     print(f"Got Exception: {e}")


def start(d_list: list[Drone], c_list: list[Connection],
          h_list: list[Hub]) -> None:
    paths: list[Hub] = []
    paths = solver(c_list, h_list)
    for hub in paths:
        hub.show()


def print_info(hubs: list[Hub], drones: list[Drone],
               connections: list[Connection]) -> None:
    for hub in hubs:
        hub.show()
    print()
    for drone in drones:
        drone.show()
    print()
    for conn in connections:
        conn.show()
    print()


if __name__ == "__main__":
    main()
