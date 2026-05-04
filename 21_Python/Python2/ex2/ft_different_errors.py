def ft_different_errors():
    print("=== Garden Error Types Demo ===")
    test_error_types()
    print()
    print("All error types tested successfully!")


def garden_operations(operation_number: int):
    if operation_number == 0:
        int('abc')
    elif operation_number == 1:
        1 / 0
    elif operation_number == 2:
        open("ciao.txt")
    elif operation_number == 3:
        "ciao" + 3
    else:
        1 + 1
        print("Operation completed successfully")


def test_error_types():
    for i in range(5):
        try:
            print(f"Testing operation {i}...")
            garden_operations(i)
        except ValueError as e:
            print(f"Caught ValueError: {e}")
        except ZeroDivisionError as e:
            print(f"Caught ZeroDivisionError: {e}")
        except FileNotFoundError as e:
            print(f"Caught FileNotFoundError: {e}")
        except TypeError as e:
            print(f"Caught FileNotFoundError: {e}")


if __name__ == "__main__":
    ft_different_errors()
