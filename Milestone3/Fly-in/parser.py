import sys


class parsingException(Exception):
    def __init__(self, msg: str):
        super().__init__(msg)
        self.msg = "parsingException found"


def check_metadata(current_line: int, line0: str) -> tuple:
    # Prende solo i metadata
    line0 = line0.split(' ', 4)
    if len(line0) == 4:
        return (0, "")
    else:
        line0 = line0.pop()

    if not line0[0].startswith('[') and line0[0] is not None:
        return (1, f"Invalid metadata format in line {current_line}")
    elif line0[0] is None:
        return (0, "")
    if line0.count('[') != line0.count(']') and line0.count(']') != 1:
        return (1, f"Invalid metadata format in line {current_line}")
    elements = line0.split(' ')
    for el in elements:
        el0 = el.split(' ')
        for el1 in el0:
            if el1.startswith('['):
                el1 = el1.split('[').pop()
            if el1.endswith(']'):
                el1 = el1.split(']', 1).pop(0)
            # Il controllo dei colori viene fatto quando si rappresenta
            # la mappa
            if (el1.startswith('color=')):
                continue
            # Controllo numero droni
            elif el1.startswith('capacity='):
                el2 = el1.split('=').pop()
                if int(el2) < 0:
                    return (1, f"Invalid max_drones value in line {current_line}")
            # Controllo zone
            elif (el == "zone=normal" or el == "zone=blocked"
                    or el == "zone=restricted" or el == "zone=priority"):
                return (0, "")
            else:
                return (1, f"Invalid metadata format in line {current_line}")
    return (0, "")


# Controlla che il file dato come parametro sia scritto correttamente
# E restituisce una lista con i valori da utilizzare per creare i droni,
# gli hub e le connessioni
def parser(new_list: list[str], text: str) -> list[str]:
    init_list = new_list

    # Controllo che tutte le coordinate siano diverse(no hub nello stesso punto)
    coordinates = list()
    for line in new_list:
        if (line.startswith('connection: ') or line.startswith('nb_drones: ')
            or line.startswith('#')):
            continue
        coord = line.split(' ')
        coord0 = coord[2] + ' ' + coord[3]
        coordinates.append(coord0)
    for cord in coordinates:
        if coordinates.count(cord) > 1:
            raise parsingException("Same coordinates in more than a hub in "
                                    f"line {get_line(text, cord)}")

    hub_list = list()
    for line in new_list:
        if (line.startswith('start_hub: ') or line.startswith('hub: ')
           or line.startswith('end_hub: ')):
            hub_list.append(line)
    # Controllo che tutti i nomi siano diversi
    for name0 in hub_list:
        for name1 in hub_list:
            if name0 == name1:
                continue
            name0 = name0.split(' ')
            name1 = name1.split(' ')
            if (name0[1] == name1[1]):
                raise parsingException("Same hub name in more than a hub in line"
                                       f" {get_line(text, name0[1])}")
            name0 = ' '.join(name0)
            name1 = ' '.join(name1)

    connections = list()
    for line in new_list:
        if line.startswith("nb_drones: "):
            # Ottiene solo il valore dopo nb_drones
            line0 = (line.split("nb_drones: ", 1).pop())
            try:
                nb_drones = int(line0)
                if nb_drones <= 0:
                    n = get_line(text, 'nb_drones: ')
                    raise parsingException("Invalid line or number of "
                                            f"drones in line {n}.")
            except ValueError as e:
                raise parsingException(f"{e} in line "
                                        f"{get_line(text, 'nb_drones: ')}")

        # Controllo riga start_hub
        elif line.startswith("start_hub: "):
            list0 = line.split(' ')
            list0.pop(0)
            start_name = list0.pop(0)
            try:
                int(list0[0])
                int(list0[1])
            except ValueError as e:
                raise parsingException(f"{e} in line "
                                        f"{get_line(text, 'start_hub: ')}")
            check = check_metadata(get_line(text, 'start_hub: '), line)
            if check[0] == 1:
                raise parsingException(check[1])

        # Controllo riga end_hub
        elif line.startswith("end_hub: "):
            list0 = line.split(' ')
            list0.pop(0)
            end_name = list0.pop(0)
            try:
                int(list0[0])
                int(list0[1])
            except ValueError as e:
                raise parsingException(f"{e} in line "
                                        f"{get_line(text, 'end_hub: ')}")
            check = check_metadata(get_line(text, 'end_hub: '), line)
            if check[0] == 1:
                raise parsingException(check[1])

        # Controllo righe hub
        elif line.startswith("hub: "):
            list0 = line.split(' ')
            list0.pop(0)
            hub_name = list0.pop(0)
            try:
                int(list0[0])
                int(list0[1])
            except ValueError as e:
                raise parsingException(f"{e} in line "
                                        f"{get_line(text, 'hub: ')}")
            check = check_metadata(get_line(text, f'hub: {hub_name}'), line)
            if check[0] == 1:
                raise parsingException(check[1])

        # Controllo righe connection
        if line.startswith('connection: '):
            connections.append(line)

    start = 0
    end = 0
    for i in range(len(connections)):
        if start_name in connections[i]:
            start += 1
        if end_name in connections[i]:
            end += 1
        for j in range(len(connections)):
            if connections[i] == connections[j] and j != i:
                raise parsingException("Duplicated connection found in line "
                                       f"{get_line(text, connections[j])}")
    if end == 0 or start == 0:
        raise parsingException("No 'start_hub' and/or 'end_hub' connections")
    for el in connections:
        el2 = ""
        # Rimuove 'connection: '
        el0 = el.split(' ')
        el0.pop(0)
        if len(el0) == 1:
            el1 = el0[0].split('-').pop()
            el0 = el0[0].split('-').pop(0)
        elif len(el0) == 2:
            el1 = el0[0].split('-').pop()
            el2 = el0[1]
            el0 = el0[0].split('-').pop(0)
        else:
            raise parsingException("Invalid 'connection: ' line in line "
                                   f"{get_line(text, el)}")
        if el0 == el1:
            raise parsingException("Repeated hub in the same connection in "
                                   f"line {get_line(text, el)}")
        if (el2 != "" and not el2.startswith('[max_link_capacity=')):
            raise parsingException("Invalid 'connection: ' line in line "
                                   f"{get_line(text, el)}")
        if el2 != "":
            # Controllo metadata di connection
            n = el2.split("[max_link_capacity=").pop()
            n = n.split("]").pop(0)
            try:
                if int(n) < 1:
                    raise parsingException("Invalid max_link_capacity value "
                                           f"in line {get_line(text, el)}")
            except ValueError as e:
                raise parsingException(f"{e} in line {get_line(text, el)}")
        c = el1 + "-" + el0
        for conn in connections:
            if c in conn:
                raise parsingException("Repeated connection in line "
                                       f"{get_line(text, c)}")

    return init_list


def get_values(argv: list[str]) -> list[str]:
    x = 0
    current_line = 0
    new_list = []
    with open(argv[1], "r") as f:
        text = f.readlines()

    # Controllo numero di volte in cui e' presente una determinata riga
    nb_drones_line = 0
    start_line = 0
    end_line = 0
    connection_line = 0
    for line in text:
        current_line += 1
        if line.startswith('#') or line == "\n":
            continue

        if not line.startswith("nb_drones: "):
            x += 1
        if line.startswith("nb_drones: "):
            nb_drones_line += 1
            if x == 0:
                new_list.append(line.split('\n').pop(0))
                x += 1
            else:
                raise parsingException("'nb_drones: ...' line isn't the first"
                                       " one in line "
                                       f"{get_line(argv[1], 'nb_drones')}")

        elif line.startswith("start_hub: "):
            start_line += 1
            new_list.append(line.split('\n').pop(0))

        elif line.startswith("hub: "):
            new_list.append(line.split('\n').pop(0))

        elif line.startswith("end_hub: "):
            end_line += 1
            new_list.append(line.split('\n').pop(0))

        elif line.startswith("connection: "):
            connection_line += 1
            new_list.append(line.split('\n').pop(0))

        else:
            raise parsingException(f"Invalid line in line {current_line}")
    if nb_drones_line != 1:
        print(nb_drones_line)
        raise parsingException("Too many or 0 'nb_drones: ...' lines in "
                               f"line {get_line(argv[1], 'nb_drones: ')}")
    if start_line != 1:
        raise parsingException("Too many or 0 'start_hub: ...' lines in "
                               f"line {get_line(argv[1], 'start_hub: ')}")
    if end_line != 1:
        raise parsingException("Too many or 0 'end_hub: ...' lines in "
                               f"line {get_line(argv[1], 'end_hub: ')}")
    if connection_line == 0:
        raise parsingException("0 'connection: ...' lines")
    return new_list


# Restituisce in quale riga si trova quella parte di testo
def get_line(file: str, find: str) -> int:
    n = 1
    with open(file, "r") as f:
        x = f.readlines()
        for line in x:
            if find in line:
                return n
            n += 1
    return -1


def init_hubs(list0: list[str]):
    print("ciao")


def main():
    argv = sys.argv
    # try:
    list0 = get_values(argv)
    if parser(list0, argv[1]) == 0:
        init_hubs(list0)
    # except parsingException as e:
    #     print(f"Got parsing Exception: {e}")
    # except Exception as e:
    #     print(f"Got Exception: {e}")


if __name__ == "__main__":
    main()
