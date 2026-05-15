import alchemy


if __name__ == "__main__":
    print("=== Alembic 4 ===")
    print("Accessing alchemy module using 'import alchemy'")
    print(f"Testing create_air: {alchemy.create_air()}")
    print("Now show that not all functions can be reached")
    try:
        print(f"Testing create_earth: {alchemy.create_earth()}")
    except Exception as e:
        print(f"Got error: {e}")
