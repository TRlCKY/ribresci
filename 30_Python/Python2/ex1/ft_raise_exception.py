def ft_raise_exception():
    print("=== Garden Temperature Checker ===")
    print()
    test_temperature()


def input_temperature(temp_str: str) -> int:
    try:
        int_value = int(temp_str)
        if int_value >= 0 and int_value <= 40:
            return int_value
        elif int_value < 0:
            print(f"Caught input_temperature error: {int_value}°C is too cold"
                  " for plants (min 0°C)")
        else:
            print(f"Caught input_temperature error: {int_value}°C is too hot"
                  " for plants (max 40°C)")
    except Exception as e:
        print(f"Caught input_temperature error: {e}")


def test_temperature():
    print("Input data is '25'")
    print(f"Temperature is now {input_temperature('25')}")
    print()
    print("Input data is 'abc'")
    input_temperature('abc')
    print()
    print("Input data is '100'")
    input_temperature('100')
    print()
    print("Input data is '-50'")
    input_temperature('-50')
    print()
    print("All tests completed - program didn't crash!")


if __name__ == "__main__":
    ft_raise_exception()
