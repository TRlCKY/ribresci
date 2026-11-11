from classes import Connection, Hub


def sort_list(hub: Hub) -> int:
    if hub.type == "start":
        return 0
    elif hub.type == "end":
        return 2
    else:
        return 1


def solver(c_list: list[Connection], h_list: list[Hub]) -> list[Hub]:
    paths: list[list[Hub]] = []
    h_list.sort(key=sort_list)
    for hub in h_list:
        if hub.type == "start":
            curr_hub = hub
            curr_hub.show()
        if hub.type == "end":
            end_hub = hub
            end_hub.show()
    curr_hub.visited = True
    while curr_hub.name != end_hub.name:
        path: list[Hub] = []
        possibile_hubs: list[Hub] = []
        path.append(curr_hub)
        for hub in h_list:
            for near in curr_hub.connected:
                if (near[1] == hub.name and hub.visited is False
                   and hub.zone != 'blocked'):
                    possibile_hubs.append(hub)
        if len(possibile_hubs) > 0:
            for pos in possibile_hubs:
                for pos0 in pos.connected:
                    pos0.path = update_path()
    for final_path in end_hub.path:
        paths.append(final_path)
    return paths


def update_path(h_list: list[Hub], prev_h: Hub,
                next_h: Hub) -> None:
    next_h.append([])
