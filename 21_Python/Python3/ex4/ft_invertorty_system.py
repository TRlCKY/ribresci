import sys


def convert_and_check(inv: dict[str, int], a: list) -> dict[str, int]:
    if len(a) != 2:
        raise Exception("Missing or too many ':'")
    x = len(inv)
    value_inv = list(inv.keys())
    for i in range(x):
        if value_inv[i] == a[0]:
            raise Exception(f"Redundant item '{a[0]}' - discarding")
        if int(a[1]) <= 0:
            raise Exception("Given number is negative or equal to 0")
    inv.update({a[0]: int(a[1])})
    return inv


def main():
    inventory = {}
    print("=== Inventory System Analysis ===")
    x = len(sys.argv)
    if x > 1:
        for i in range(x):
            if i != 0:
                try:
                    a = list(sys.argv[i].split(':'))
                    inventory = convert_and_check(inventory, a)
                    print(f"New item added: {a[0]}: {a[1]}")
                except Exception as e:
                    print(f"Error - {e}")
                except ValueError as e:
                    print(f"Quantity error - {e}")
    print()
    print(f"Got inventory: {inventory}")
    print(f"Item list: {list(inventory.keys())}")
    print()
    total_num = 0
    names = list(inventory.keys())
    quantity = list(inventory.values())
    num_item = len(inventory)
    for i in range(num_item):
        total_num += quantity[i]
    print(f"Total quantity of the {num_item} items: {total_num}")
    percent = 0.0
    for i in range(num_item):
        percent = 100 * quantity[i] / total_num
        print(f"Item {names[i]} represents {percent:.1f}%")
    if num_item >= 1:
        most_item = 0
        for i in range(num_item):
            if quantity[i] > most_item:
                most_item = i
        print(f"Item most abundant: {names[most_item]} with quantity "
              f"{quantity[most_item]}")
        if num_item == 1:
            print(f"Item least abundant: {names[most_item]} with quantity "
                  f"{quantity[most_item]}")
        else:
            least_item = quantity[most_item]
            for i in range(num_item):
                if quantity[i] < least_item:
                    least_item = i
            print(f"Item least abundant: {names[least_item]} with quantity "
                  f"{quantity[least_item]}")
    inventory.update({"Useless rock": 999})
    print(f"Updated inventory: {inventory}")


if __name__ == "__main__":
    main()
