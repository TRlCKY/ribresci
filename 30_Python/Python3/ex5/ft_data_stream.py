import typing
import random


def consume_event(event_list: list):
    i = len(event_list) - 1
    x = random.randint(0, i)
    yield event_list.remove(x)


def gen_event() -> tuple:
    player = ["Jojo", "TonyPitony", "Gabibbo", "Batman"]
    actions = ["is dancing", "is healing", "is trying to not die",
               "is doing nothing", "attacks the enemy but missed",
               "attacks the enemy", "attacks the enemy. A critical hit!",
               "dodged the enemy's attack"]
    len_p = len(player) - 1
    len_a = len(actions) - 1
    name = player[random.randint(0, len_p)]
    action = actions[random.randint(0, len_a)]
    tuple0 = tuple((name, action))
    return tuple0


def main():
    print("=== Game Data Stream Processor ===")
    tuple_e = tuple()
    for i in range(1000):
        tuple_e = gen_event()
        print(f"Event {i}: Player {tuple_e[0]} {tuple_e[1]}")
    print()
    event_list = list()
    for i in range(10):
        event = gen_event()
        event_list.append(event)
    print(f"Built list of 10 events: {event_list}")
    print()
    for i in range(10):
        consume_event(event_list)


if __name__ == "__main__":
    main()
