class Drone():
    def __init__(self, id: int):
        self.id = id
        self.visited: list[str] = []

    def show(self) -> None:
        print(f"Id: {self.id}. Visited: {self.visited}")


def init_drones(init_list: list[str]) -> list[Drone]:
    n = 0
    drone_list: list[Drone] = []
    for line in init_list:
        if line.startswith('nb_drones: '):
            line0 = line.split('nb_drones: ').pop()
            n = int(line0)
            break
    for i in range(n):
        drone = Drone(i)
        drone_list.append(drone)
    return drone_list


class Hub():
    def __init__(self, name: str, x: float, y: float, zone: str, color: str,
                 max_drones: int, cost: int):
        self.name = name
        self.x = x
        self.y = y
        self.zone = zone
        self.color = color
        self.max_drones = max_drones
        self.cost = cost

    def show(self) -> None:
        print(f"Name: {self.name}. X-Y: {self.x}-{self.y}. Zone: {self.zone}. "
              f"Color: {self.color}. Max_drones: {self.max_drones}. "
              f"Cost: {self.cost}")


def init_hubs(init_list: list[str]) -> list[Hub]:
    hub_list: list[Hub] = []
    zone = "normal"
    color = "none"
    max_drones = 1
    for line in init_list:
        cost = 1
        if (line.startswith('start_hub: ') or line.startswith('hub: ')
           or line.startswith('end_hub: ')):
            line0 = line.split(' ', 4)
            meta0 = line0[4].split(' ')
            for meta in meta0:
                if meta.startswith('['):
                    meta = meta.split('[').pop()
                if meta.endswith(']'):
                    meta = meta.split(']').pop(0)
                if meta.startswith('zone='):
                    zone = meta.split('zone=').pop()
                    if zone == 'restricted':
                        cost = 2
                    if zone == 'blocked':
                        cost = -1
                if meta.startswith('color='):
                    color = meta.split('color=').pop()
                if meta.startswith('max_drones='):
                    max_drones = int(meta.split('max_drones=').pop())
                    if (line0[0].startswith('start_hub:')
                       or line0[0].startswith('end_hub:')):
                        max_drones = -1
            hub0 = Hub(line0[1], float(line0[2]), float(line0[3]), zone, color,
                       max_drones, cost)
            hub_list.append(hub0)
    return hub_list


class Connection():
    def __init__(self, hub0: Hub, hub1: Hub, max_link_capacity: int):
        self.hub0 = hub0
        self.hub1 = hub1
        self.max_link_capacity = max_link_capacity

    def show(self) -> None:
        print(f"Hub0: {self.hub0.name}. Hub1: {self.hub1.name}. "
              f"Max_link_capacity: {self.max_link_capacity}\n")


def init_connections(init_list: list[str],
                     hub_list: list[Hub]) -> list[Connection]:
    max = 1
    connection_list: list[Connection] = []
    for line in init_list:
        if line.startswith('connection: '):
            line0 = line.split(' ')
            hub01 = line0[1].split('-')
            hub0 = hub01[0]
            hub1 = hub01[1]
            for hub in hub_list:
                if hub0 == hub.name:
                    hub00 = hub
                if hub1 == hub.name:
                    hub11 = hub
            if len(line0) == 3:
                max0 = line0[2].split('[max_link_capacity=').pop()
                max0 = max0.split(']').pop(0)
                max = int(max0)
            connection = Connection(hub00, hub11, max)
            connection_list.append(connection)
    return connection_list
