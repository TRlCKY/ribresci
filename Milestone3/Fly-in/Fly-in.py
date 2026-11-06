import sys
from parser import parser, get_values, ParsingException
from classes import init_hubs, init_drones, init_connections
# from classes import Drone, Hub, Connection


def start() -> None:
    argv = sys.argv
    # try:
    list0 = get_values(argv)
    parser(list0, argv[1])
    hubs = init_hubs(list0)
    drones = init_drones(list0)
    connections = init_connections(list0, hubs)
    for hub in hubs:
        hub.show()
    for drone in drones:
        drone.show()
    for conn in connections:
        conn.show()
    # except ParsingException as e:
    #     print(f"Got parsing Exception: {e}")
    # except Exception as e:
    #     print(f"Got Exception: {e}")


if __name__ == "__main__":
    start()
