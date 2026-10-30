import sys


class parsingException(Exception):
    def __init__(self):
        self.msg = ""


def check_metadata(current_line: int, line0: list[str]) -> tuple:
    # Controllo metadata
    line0.pop(0)
    line0.pop(0)
    if not line0[0].startswith('[') and line0[0] is not None:
        return (1, f"Invalid metadata format in line {current_line}")
    elif line0[0] is None:
        return (0, "")
    line1 = " ".join(line0)
    if not line1.endswith(']'):
        return (1, f"Invalid metadata format in line {current_line}")
    if line1.count('[') != line1.count(']') and line1.count(']') != 1:
        return (1, f"Invalid metadata format in line {current_line}")
    for el in line0:
        if el.startswith('['):
            el = el.split('[').pop()
        elif el.endswith(']'):
            el = el.split(']').pop()
        # Il controllo dei colori viene fatto quando si rappresenta
        # la mappa
        elif (el.startswith('color=')):
            return (0, "")
        # Controllo numero droni
        elif el.startswith('max_drones='):
            el0 = el.split('=').pop()
            if int(el0) < 0:
                return (1, f"Invalid max_drones value in line {current_line}")
        # Controllo zone
        elif (el != "zone=normal" and el != "zone=blocked"
                and el != "zone=restricted" and el != "zone=priority"):
            return (1, f"Invalid metadata format in line {current_line}")
        return (0, "")
    return (0, "")


# Controlla che il file dato come parametro sia scritto correttamente
# E restituisce una lista con i valori da utilizzare per creare i droni,
# gli hub e le connessioni
def parser(new_list: list[list[str]], text: str) -> list[list[str]]:
    init_list = new_list
    # Viene separato il testo in righe a cui viene rimosso lo '\n'
    for line in new_list:
        if line.startswith("nb_drones: "):
            line = line.split('\n', 1).pop(0)
            # Ottiene solo il valore dopo nb_drones
            line0 = (line.split("nb_drones: ", 1).pop())
            try:
                nb_drones = int(line0)
                if nb_drones <= 0:
                    raise parsingException("Invalid line or number of drones "
                                           "in line "
                                           f"{get_line(text, 'nb_drones: ')}.")
            except ValueError as e:
                raise parsingException(f"{e} in line "
                                       f"{get_line(text, 'nb_drones: ')}")

        # Controllo riga start_hub
        elif line.startswith("start_hub: "):
            list0 = line.split(' ')
            list0.pop(0)
            start_hub = list0.pop(0)
            try:
                int(list0[0])
                int(list0[1])
            except ValueError as e:
                raise parsingException(f"{e} in line "
                                       f"{get_line(text, 'start_hub: ')}")
            check = check_metadata(1, line, new_list, list0)
            if check[0] == 1:
                raise parsingException(check[1])

        # Controllo riga end_hub
        elif line.startswith("end_hub: "):
            list0 = line.split(' ')
            list0.pop(0)
            end_hub = list0.pop(0)
            try:
                int(list0[0])
                int(list0[1])
            except ValueError as e:
                raise parsingException(f"{e} in line "
                                       f"{get_line(text, 'end_hub: ')}")
            check = check_metadata(1, line, new_list, list0)
            if check[0] == 1:
                raise parsingException(check[1])

        # Controllo righe hub
        elif line.startswith("hub: "):
            list0 = line.split(' ')
            list0.pop(0)
            list0.pop(0)
            try:
                int(list0[0])
                int(list0[1])
            except ValueError as e:
                raise parsingException(f"{e} in line "
                                       f"{get_line(text, 'hub: ')}")
            check = check_metadata(1, line, new_list, list0)
            if check[0] == 1:
                raise parsingException(check[1])

        # Controllo righe connection
        connections = list()
        if line.startswith('connection: '):
            connections.append(line)

    start = 0
    end = 0
    for i in range(len(connections)):
        if start_hub in connections[i]:
            start += 1
        if end_hub in connections[i]:
            end += 1
        for j in range(len(connections)):
            if connections[i] == connections[j] and j != i:
                raise parsingException("Duplicated connection found in line "
                                       f"{get_line(text, connections[j])}")
    if end == 0 or start == 0:
        raise parsingException("No 'start_hub' and/or 'end_hub' connections")
    for el in connections:
        # Rimuove 'connection: '
        el0 = el.split(' ')
        el0.remove(0)
        if len(el0) == 1:
            el1 = el0[0].split('-').pop()
            el0 = el0[0].split('-').pop(0)
        elif len(el1) == 2:
            el1 = el0[0].split('-').pop()
            el2 = el0[1]
            el0 = el0[0].split('-').pop()
        else:
            raise parsingException("Invalid 'connection: ' line in line "
                                   f"{get_line(text, el)}")
        if el0[0] == el1[0]:
            raise parsingException("Repeated hub in the same connection in "
                                   f"line {get_line(text, el)}")
        if (el2 and not el2.startswith('[max_link_capacity=')):
            raise parsingException("Invalid 'connection: ' line in line "
                                   f"{get_line(text, el)}")
        else:
            # Controllo metadata di connection
            n = el2.split("[max_link_capacity=").pop()
            n = el2.split("]").pop(0)
            try:
                if int(n) < 1:
                    raise parsingException("Invalid max_link_capacity value "
                                           f"in line {get_line(text, el)}")
            except ValueError as e:
                raise parsingException(f"{e} in line {get_line(text, el)}")
        c = el1 + "-" + el0
        if c in connections:
            raise parsingException("Repeated connection in line "
                                   f"{get_line(text, c)}")

    return init_list


def get_values(argv: list[str]) -> list[list[str]]:
    x = 0
    current_line = 0
    new_list = [['nb_drones'], ['start_hub'], ['hubs'], ['end_hub'],
                ['connection']]
    with open(argv[1], "r") as f:
        text = f.readlines()

    # Controllo numero di volte in cui e' presente una determinata riga
    nb_drones_line = text.count("nb_drones: ")
    start_line = text.count("start_hub: ")
    end_line = text.count("end_hub: ")
    connection_line = text.count("connection: ")
    if nb_drones_line != 1:
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
    for line in text:
        current_line += 1
        if line.startswith('#') or line == "\n":
            continue

        if line.startswith("nb_drones: "):
            if x == 0:
                new_list[0].append(line)
                x = 1
            else:
                raise parsingException("'nb_drones: ...' line isn't the first"
                                       " one in line "
                                       "{get_line(argv[1], 'nb_drones')}")

        elif line.startswith("start_hub: "):
            new_list[1].append(line)

        elif line.startswith("hub: "):
            new_list[2].append(line)

        elif line.startswith("end_hub: "):
            new_list[3].append(line)

        elif line.startswith("connection: "):
            new_list[4].append(line)

        else:
            raise parsingException(f"Invalid line in line {current_line}")
    return new_list


def get_line(file: str, find: str) -> int:
    n = 1
    with open(file, "r") as f:
        x = f.readlines()
        for line in x:
            if find in line:
                return n
            n += 1
    return -1


def init_hubs(list0: list[list[str]]):
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
