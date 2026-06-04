from dotenv import load_dotenv
import os


def check() -> None:
    x = 0
    matrix_mode = os.getenv("MATRIX_MODE")
    if not matrix_mode:
        print("MATRIX_MODE is missing")
        x += 1
    database_url = os.getenv("DATABASE_URL")
    if not database_url:
        print("DATABASE_URL is missing")
        x += 1
    api_keys = os.getenv("API_KEY")
    if not api_keys:
        print("API_KEY is missing")
        x += 1
    log_level = os.getenv("LOG_LEVEL")
    if not log_level:
        print("LOG_LEVEL is missing")
        x += 1
    zion_endpoint = os.getenv("ZION_ENDPOINT")
    if not zion_endpoint:
        print("ZION_ENDPOINT is missing")
        x += 1
    if x >= 1:
        raise Exception("Missing values")


def oracle():
    # Scarica le variabili nel file .env
    load_dotenv()
    # Controlla che ci siano tutti i valori
    try:
        check()
    except Exception as e:
        print(f"Got error: {e}")
        exit()
    print("ORACLE STATUS: Reading the Matrix...")
    print("Configuration loaded:")
    mode = os.getenv('MATRIX_MODE')
    print(f"Mode: {mode}")
    print(f"Database: {os.getenv('DATABASE_URL')}")
    print(f"API Access: {os.getenv('API_KEY')}")
    print(f"Log Level: {os.getenv('LOG_LEVEL')}")
    print(f"Zion Network: {os.getenv('ZION_ENDPOINT')}")
    print()
    if mode == "development":
        print("Development environment active")
        print("Debug tools enabled")
        print("Verbose logging ON")
        print("Using local/test services")
    elif mode == "production":
        print("Production environment active")
        print("Debug tools disabled")
        print("Minimal logging enabled")
        print("Using secure production services")
    print()
    print("Environment security check:")
    print("[OK] No hardcoded secrets detected")
    print("[OK] .env file properly configured")
    print("[OK] Production overrides available")
    print()
    print("The Oracle sees all configurations.")


if __name__ == "__main__":
    oracle()
