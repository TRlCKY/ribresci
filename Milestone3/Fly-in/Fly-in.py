import sys
from parser import parser, get_values, ParsingException
from classes import init_hubs, init_drones, init_connections
from solver import dijsktras
from classes import Drone, Hub, Connection


def main() -> None:
    argv = sys.argv
    try:
        if len(argv) != 2:
            raise Exception("Number of arguments isn't 2. Wronge")
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
        start(drones, connections, hubs)
    except ParsingException as e:
        print(f"Got parsing Exception: {e}")
    except Exception as e:
        print(f"Got Exception: {e}")


def start(d_list: list[Drone], c_list: list[Connection],
          h_list: list[Hub]) -> None:
    paths: list[Hub] = []
    paths = dijsktras(c_list, h_list)
    paths


if __name__ == "__main__":
    main()
