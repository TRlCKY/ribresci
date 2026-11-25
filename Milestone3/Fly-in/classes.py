class ParsingException(Exception):
    def __init__(self, msg: str):
        super().__init__(msg)
        self.msg = "parsingException found"


class Connection():
    def __init__(self, hub0: "Hub", hub1: "Hub", max_link_capacity: int):
        self.hub0 = hub0
        self.hub1 = hub1
        self.max_link_capacity = max_link_capacity
        self.drones_inside: int = 0

    def show(self) -> None:
        print(f"HUB0: {self.hub0.name}. HUB1: {self.hub1.name}. "
              f"MAX_LINK_CAPACITY: {self.max_link_capacity}")


class Hub():
    def __init__(self, name: str, x: int, y: int, zone: str, color: str,
                 max_drones: int, type: str, cost: int,
                 connected: list[Connection],
                 path: list["Hub"]):
        self.name = name
        self.x = x
        self.y = y
        self.zone = zone
        self.color = color
        self.max_drones = max_drones
        self.type = type
        self.cost = cost
        self.connected = connected
        self.visited = False
        self.path = path
        self.current_drones: int = 0
        self.waiting_drones: list[Drone] = []

    def show(self) -> None:
        print(f"NAME: {self.name}. X-Y: {self.x}-{self.y}. ZONE: {self.zone}."
              f"COLOR: {self.color}. MAX_DRONES: {self.max_drones}. "
              f"TYPE: {self.type}. COST: {self.cost}. "
              f"VISITED: {self.visited}.\nCONNECTION:")
        for c in self.connected:
            print(f"{c.hub0.name}-{c.hub1.name}")


class Drone():
    def __init__(self, id: int):
        self.id: int = id + 1
        self.visited: list[str] = []
        self.prev_hub: Hub | None = None
        self.current_hub: Hub | None = None
        self.next_hub: Hub | None = None
        self.status: str = ""
        self.prev_connection: Connection | None = None
        self.current_connection: Connection | None = None

    def show(self) -> None:
        visited = ''
        if self.visited is not []:
            for h in self.visited:
                visited += f'{h.name}, '
        else:
            visited = 'none'
        prev_hub = ''
        if self.prev_hub is not None:
            prev_hub = f'{self.prev_hub.name}'
        else:
            prev_hub = 'none'
        curr_hub = ''
        if self.curr_hub is not None:
            curr_hub = f'{self.curr_hub.name}'
        else:
            curr_hub = 'none'
        print(f"ID: {self.id}. VISITED: {visited}. "
              f"PREVIOS HUB: {prev_hub}. "
              f"CURRENT HUB: {curr_hub}. "
              f"NEXT HUB: {self.next_hub.name}. "
              f"PREVIOS CONNECTION: {self.prev_connection.hub0.name}-"
              f"{self.prev_connection.hub1.name}. "
              f"CURRENT CONNECTION: {self.current_connection.hub0.name}-"
              f"{self.current_connection.hub1.name}. STATUS: {self.status}")

    def print_status(self, hub: Hub) -> None:
        if self.status == "wait":
            print(f"Drone {self.id} is waiting in hub '{hub.name}'")
        if self.status == "reach":
            print(f"Drone {self.id} reached hub '{hub.name}'")
        if self.status == "restricted":
            print(f"Drone {self.id} is reaching a restricted hub")
        if self.status == "finish":
            return
        self.show()


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


def init_hubs(init_list: list[str]) -> list[Hub]:
    hub_list: list[Hub] = []
    for line in init_list:
        zone = "normal"
        color = "none"
        max_drones = 1
        type = "hub"
        cost = 1
        if (line.startswith('start_hub: ') or line.startswith('hub: ')
           or line.startswith('end_hub: ')):
            line0 = line.split(' ', 4)
            meta0 = line0[4].split(' ')
            if (line0[0].startswith('start_hub:')
               or line0[0].startswith('end_hub:')):
                max_drones = int(init_list[0].split('nb_drones: ').pop())
            if line0[0].startswith('start_hub:'):
                type = "start"
            if line0[0].startswith('end_hub:'):
                type = "end"
                cost = 1
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
                    if zone == 'priority' or zone == 'normal':
                        cost = 1
                if meta.startswith('color='):
                    color = meta.split('color=').pop()
                if (meta.startswith('max_drones=') and type != "start"
                   and type != "end"):
                    max_drones = int(meta.split('max_drones=').pop())
            hub0 = Hub(line0[1], int(line0[2]), int(line0[3]), zone, color,
                       max_drones, type, cost, [], [])
            hub_list.append(hub0)
    return hub_list


# Aggiunge ai droni i loro vicini con i rispettivi costi
def get_connected(connections: list[Connection],
                  hubs: list[Hub]) -> None:
    for hub in hubs:
        for conn in connections:
            if hub.name == conn.hub0.name or hub.name == conn.hub1.name:
                hub.connected.append(conn)


def init_connections(init_list: list[str],
                     hub_list: list[Hub]) -> list[Connection]:
    connection_list: list[Connection] = []
    for line in init_list:
        if line.startswith('connection: '):
            line0 = line.split(' ')
            hub01 = line0[1].split('-')
            hub0 = hub01[0]
            hub1 = hub01[1]
            max = 1
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
