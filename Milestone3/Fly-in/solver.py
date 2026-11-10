from classes import Connection, Hub


def dijsktras(c_list: list[Connection],
              h_list: list[Hub]) -> list[Hub]:
    paths: list[Hub] = []
    for hub in h_list:
        if hub.type == "start":
            curr_hub = hub
        if hub.type == "end":
            end_hub = hub
    paths.append(curr_hub)
    while curr_hub.name != end_hub.name:
        possibile_hubs: list[Hub] = []

    return paths
