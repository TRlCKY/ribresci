import sys


class parsingException(Exception):
    pass


def init_new_list() -> list[list[str]]:
    list0 = list[list[str]]
    list0[0][0] = "nb_drones"
    list0[1][0] = "start_hub"
    list0[2][0] = "end_hub"
    list0[3][0] = "hubs"
    list0[4][0] = "connection"
    return list0


# Controlla che il file dato come parametro sia scritto correttamente
def parser(argv: list[str]) -> list[list[str]]:
    new_list = init_new_list()
    with open(argv[1], "r") as f:
        text = f.read()

    # Controllo numero di volte in cui e' presente una determinata riga
    nb_drones_line = text.count("nb_drones: ")
    start_line = text.count("start_hub ")
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
    # Viene separato il testo in righe a cui viene rimosso lo '\n'
    for x in text.splitlines():
        x = str(x.split('\n', 1).pop(0))
        current_line += 1

        # Salta le linee che iniziano con il # o che sono vuote
        if x.startswith("#") or x == "":
            continue

        # Controllo riga nb_drones
        if x.startswith("nb_drones: "):
            # Ottiene solo il valore dopo nb_drones
            line0 = (x.split("nb_drones: ", 1).pop())
            try:
                nb_drones = int(line0)
                if nb_drones <= 0:
                    raise parsingException("Invalid line or number of drones "
                                           f"in line {current_line}.")
                new_list[0].append(str(nb_drones))
            except ValueError as e:
                print(f"Got Parser Error : {e}")

        # Controllo riga start_hub
        if x.startswith("start_hub: "):
            line0 = x.split(' ')
            line0.pop(0)

        # Controllo riga end_hub
        if x.startswith("end_hub: "):
            line0 = x.split(' ')
            line0.pop(0)

        # Controllo righe hub
        if x.startswith("hub: "):
            line0 = x.split(' ')
            line0.pop(0)

        # Controllo righe connection
        if x.startswith("connection: "):
            line0 = x.split(' ')
            line0.pop(0)
    return 1


def init_hubs(list0: list[list[str]]):
    print()


def main():
    argv = sys.argv
    try:
        new_list = parser(argv)
    except parsingException as e:
        print(e)
    init_hubs(new_list)


if __name__ == "__main__":
    main()
