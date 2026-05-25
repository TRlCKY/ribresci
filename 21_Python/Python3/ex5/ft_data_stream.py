import typing
import random


def gen_event() -> typing.Generator:
    player = ["Jojo", "TonyPitony", "Gabibbo", "Batman"]
    actions = ["is dancing", "is healing", "is trying to not die",
               "is doing nothing", "attacks the enemy but missed",
               "attacks the enemy", "attacks the enemy. A critical hit!",
               "dodged the enemy's attack"]
    while True:
        name = random.choice(player)
        action = random.choice(actions)
        yield (name, action)


def consume_event(event_list: list) -> typing.Generator:
    while event_list:
        i = len(event_list) - 1
        x = random.randint(0, i)
        print(f"Got event from list: {event_list[x]}")
        yield event_list.pop(x)


def main():
    print("=== Game Data Stream Processor ===")
    events = gen_event()
    for i in range(1000):
        tuple_e = next(events)
        print(f"Event {i}: Player {tuple_e[0]} {tuple_e[1]}")
    print()
    event_list = list()
    for i in range(10):
        event_list.append(next(events))
    print(f"Built list of 10 events: {event_list}")
    print()
    consume_list = consume_event(event_list)
    for i in consume_list:
        consume_event(event_list)
        print(f"Remains in list: {event_list}\n")


if __name__ == "__main__":
    main()
