from classes import Hub, Connection


def sort_list(hub: Hub) -> int:
    if hub.type == "start":
        return 0
    elif hub.type == "end":
        return 2
    else:
        return 1


def get_near_hubs(curr_hub: Hub, hub_list: list[Hub]) -> list[Hub]:
    near_hubs: list[Hub] = []
    for hub in hub_list:
        for near in curr_hub.connected:
            if ((near.hub0.name == hub.name or near.hub1.name == hub.name)
               and hub.visited is False and hub.zone != 'blocked'):
                near_hubs.append(hub)
    return near_hubs


def solver(hub_list: list[Hub], connections: list[Connection]) -> list[Hub]:
    paths: list[list[Hub]] = []
    hub_list.sort(key=sort_list)
    for hub in hub_list:
        if hub.type == "start":
            curr_hub = hub
        if hub.type == "end":
            end_hub = hub
    curr_hub.visited = True
    heap: list[tuple[int, str]] = [(0, end_hub.name)]
    while heap:
        dist, name = heap
        path: list[Hub] = []
        near_hubs = get_near_hubs(curr_hub, hub_list)
        
        # path.append(curr_hub)
        # if len(near_hubs) > 0:
        #     for pos in near_hubs:
        #         for pos0 in pos.connected:
        #             if pos.name == pos0.hub0.name:
        #                 update_path(curr_hub, pos0.hub1)
        #             if pos.name == pos0.hub1.name:
        #                 update_path(curr_hub, pos0.hub0)
        # curr_hub.visited = True
    for final_path in end_hub.path:
        print(f"Final path: {final_path.name}")
        paths.append(final_path)
    return paths


def update_path(prev_h: Hub, next_h: Hub) -> None:
    new_path = prev_h.path
    new_path.append(next_h)
    next_h.path = new_path
