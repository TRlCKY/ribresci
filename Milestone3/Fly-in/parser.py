import sys


class parsingException(Exception):
    pass


def check_metadata(current_line: int, x: str, new_list: list[list[str]],
                   line0: list[str]) -> tuple:
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
def parser(argv: list[str]) -> list[list[str]]:
    new_list = [['nb_drones'], ['start_hub'], ['end_hub'], ['hubs'],
                ['connection']]
    with open(argv[1], "r") as f:
        text = f.read()

    # Controllo numero di volte in cui e' presente una determinata riga
    nb_drones_line = text.count("nb_drones: ")
    start_line = text.count("start_hub: ")
    end_line = text.count("end_hub: ")
    connection_line = text.count("connection: ")
    if nb_drones_line != 1:
        raise parsingException("Too many or 0 'nb_drones: ...' lines in "
                               f"line {text.find('nb_drones: ')}")
    if start_line != 1:
        raise parsingException("Too many or 0 'start_hub: ...' lines in "
                               f"line {text.find('start_hub: ')}")
    if end_line != 1:
        raise parsingException("Too many or 0 'end_hub: ...' lines in "
                               f"line {text.find('end_hub: ')}")
    if connection_line == 0:
        raise parsingException("0 'connection: ...' lines")

    current_line = 0
    connections = list()
    first = 0
    # Viene separato il testo in righe a cui viene rimosso lo '\n'
    for x in text.splitlines():
        x = str(x.split('\n', 1).pop(0))
        current_line += 1

        # Salta le linee che iniziano con il # o che sono vuote
        if x.startswith("#") or x == "":
            continue

        # Controllo riga nb_drones
        elif x.startswith("nb_drones: ") and first == 0:
            # Ottiene solo il valore dopo nb_drones
            line0 = (x.split("nb_drones: ", 1).pop())
            first = 1
            try:
                nb_drones = int(line0)
                if nb_drones <= 0:
                    raise parsingException("Invalid line or number of drones "
                                           f"in line {current_line}.")
                new_list[0].append(str(nb_drones))
            except ValueError as e:
                raise parsingException(f"{e} in line {current_line}")

        # Controllo riga start_hub
        elif x.startswith("start_hub: "):
            line0 = x.split(' ')
            line0.pop(0)
            start_hub = line0.pop(0)
            try:
                int(line0[0])
                int(line0[1])
            except ValueError as e:
                raise parsingException(f"{e} in line {current_line}")
            new_list[1].append(line0[0])
            new_list[1].append(line0[1])
            check = check_metadata(current_line, x, new_list, line0)
            if check[0] == 1:
                raise parsingException(check[1])

        # Controllo riga end_hub
        elif x.startswith("end_hub: "):
            line0 = x.split(' ')
            line0.pop(0)
            end_hub = line0.pop(0)
            try:
                int(line0[0])
                int(line0[1])
            except ValueError as e:
                raise parsingException(f"{e} in line {current_line}")
            new_list[2].append(line0[0])
            new_list[2].append(line0[1])
            check = check_metadata(current_line, x, new_list, line0)
            if check[0] == 1:
                raise parsingException(check[1])

        # Controllo righe hub
        elif x.startswith("hub: "):
            line0 = x.split(' ')
            line0.pop(0)
            line0.pop(0)
            try:
                int(line0[0])
                int(line0[1])
            except ValueError as e:
                raise parsingException(f"{e} in line {current_line}")
            new_list[3].append(line0[0])
            new_list[3].append(line0[1])
            check = check_metadata(current_line, x, new_list, line0)
            if check[0] == 1:
                raise parsingException(check[1])

        # Controllo righe connection dopo la fine del for
        elif x.startswith("connection: "):
            line0 = x.split(' ')
            line0.pop(0)
            line0.append(current_line)
            connections.append(line0[0])
        else:
            raise parsingException(f"Invalid line in line {current_line}")

    # Controllo righe connection
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
                                       f"{get_line(argv[1], connections[j])}")
    if end == 0 and start == 0:
        raise parsingException("No 'start_hub' and/or 'end_hub' connections")
    for el in connections:
        el0 = el.split('-')
        el1 = el0[1].split(' ')
        if (len(el1) > 1 and not el1[1].startswith('[max_link_capacity=')):
            raise parsingException("Invalid 'connection: ' line in line "
                                   f"{get_line(argv[1], el0[3])}")
        c = str(el1[0]) + "-" + str(el0[0])
        if c in connections:
            raise parsingException("Repeated connection in line "
                                   f"{get_line(argv[1], c)}")
        # Controllo metadata di connection
        if len(el0) > 3 and el0[3].startswith('[max_link_capacity='):
            n = el0[3].split("[max_link_capacity=")
            if int(n[1]) < 1:
                find = "max_link_capacity"
                raise parsingException("Invalid max_link_capacity value in "
                                       f"line {get_line(argv[1], find)}")
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
    list0 = parser(argv)
    init_hubs(list0)
    # except parsingException as e:
    #     print(f"Got parsing Exception: {e}")
    # except Exception as e:
    #     print(f"Got Exception: {e}")


if __name__ == "__main__":
    main()
