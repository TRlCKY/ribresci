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
        if hub.type == "end":
            end_hub = hub
    curr_hub.visited = True
    for hubbo in h_list:
        if hubbo.type == "start":
            continue
        curr_hub = hubbo
        path: list[Hub] = []
        possibile_hubs: list[Hub] = []
        path.append(curr_hub)
        for hub in h_list:
            for near in curr_hub.connected:
                if ((near.hub0 == hub.name or near.hub1 == hub.name)
                   and hub.visited is False and hub.zone != 'blocked'):
                    possibile_hubs.append(hub)
        if len(possibile_hubs) > 0:
            for pos in possibile_hubs:
                for pos0 in pos.connected:
                    if pos.name == pos0.hub0.name:
                        update_path(curr_hub, pos0.hub1)
                    if pos.name == pos0.hub1.name:
                        update_path(curr_hub, pos0.hub0)
        curr_hub.visited = True
#    for final_path in end_hub.path:
#        print(f"Final path: {final_path}")
#        paths.append(final_path)
    return paths


def update_path(prev_h: Hub, next_h: Hub) -> None:
    next_h.path.append([prev_h.path])
