def ft_first_exception():
    print("=== Garden Temperature ===")
    print()
    test_temperature()


def input_temperature(temp_str: str) -> int:
    try:
        int_value = int(temp_str)
        return int_value
    except Exception as e:
        print(f"Caught input_temperature error: {e}")
    return 0


def test_temperature():
    print("Input data is '25'")
    print(f"Temperature is now {input_temperature('25')}")
    print()
    print("Input data is 'abc'")
    input_temperature('abc')
    print()
    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    ft_first_exception()
