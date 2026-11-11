from classes import Connection, Hub


def solver(c_list: list[Connection], h_list: list[Hub]) -> list[Hub]:
    paths: list[list[Hub]] = []
    for hub in h_list:
        if hub.type == "start":
            curr_hub = hub
            curr_hub.show()
        if hub.type == "end":
            end_hub = hub
            end_hub.show()
    curr_hub.visited = True

    return paths


def update_path(h_list: list[Hub], prev_h: Hub,
                next_h: Hub) -> None:
    if len(prev_h.path) != 0:
        print()
    else:
        path: list[tuple[int, str]] = []


# while curr_hub.name != end_hub.name:
#         path: list[Hub] = []
#         possibile_hubs: list[Hub] = []
#         path.append(curr_hub)
#         for hub in h_list:
#             for near in curr_hub.connected:
#                 if (near[1] == hub.name and hub.visited is False
#                    and hub.zone != 'blocked'):
#                     possibile_hubs.append(hub)
#         if len(possibile_hubs) > 0:
#             fast = possibile_hubs[0]
#             for h in possibile_hubs:
#                 if (fast.cost > h.cost and h.visited is False
#                    and h.zone != 'blocked'):
#                     fast = h
#             curr_hub = fast
#             curr_hub.visited = True
#             paths.append(path)
#         else:
#             break
