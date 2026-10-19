import sys


class parsingException(Exception):
    pass


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
        elif x.startswith("nb_drones: "):
            # Ottiene solo il valore dopo nb_drones
            line0 = (x.split("nb_drones: ", 1).pop())
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
            try:
                int(line0[0])
                int(line0[1])
            except ValueError as e:
                raise parsingException(f"{e} in line {current_line}")
            new_list[1].extend([line0[0], line0[1]])
            # Controllo metadata
            pipo = 0

        # Controllo riga end_hub
        elif x.startswith("end_hub: "):
            line0 = x.split(' ')
            line0.pop(0)

        # Controllo righe hub
        elif x.startswith("hub: "):
            line0 = x.split(' ')
            line0.pop(0)

        # Controllo righe connection
        elif x.startswith("connection: "):
            line0 = x.split(' ')
            line0.pop(0)
        else:
            raise parsingException(f"Invalid line in line {current_line}")
    return new_list


def init_hubs(list0: list[list[str]]):
    print()


def main():
    argv = sys.argv
    try:
        list0 = parser(argv)
    except parsingException as e:
        print(e)
    init_hubs(list0)


if __name__ == "__main__":
    main()
