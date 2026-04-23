import math


def get_player_pos() -> tuple:
    x = 0
    while x == 0:
        try:
            input0 = input("Enter new coordinates as floats in format 'x,y,z':"
                           " ")
            tuple0 = tuple(input0.split(','))
            float(tuple0[0])
            float(tuple0[1])
            float(tuple0[2])
            print(f"Got a first tuple: ({tuple0[0]}, {tuple0[1]},"
                  f" {tuple0[2]})")
            print(f"It includes: X={tuple0[0]}, Y={tuple0[1]},"
                  f" Z={tuple0[2]}")
            x = 1
        except Exception:
            print("Invalid Syntax")
    return tuple0


def main():
    print("=== Game Coordinate System ===")
    print()
    print("Get a first set of coordinates")
    tuple1 = get_player_pos()
    x1 = float(tuple1[0])
    y1 = float(tuple1[1])
    z1 = float(tuple1[2])
    distance = math.sqrt((x1)**2 + (y1)**2 + (z1)**2)
    print(f"Distance to center: {distance:.4f}")
    print()
    print("Get a second set of coordinates")
    print("Get a new set of coordinates")
    tuple2 = get_player_pos()
    x2 = float(tuple2[0])
    y2 = float(tuple2[1])
    z2 = float(tuple2[2])
    distance1 = math.sqrt((x2-x1)**2 + (y2-y1)**2 + (z2-z1)**2)
    print(f"Distance between the 2 sets of coordinates: {distance1:.4f}")


if __name__ == "__main__":
    main()
