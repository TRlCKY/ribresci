# Authorized: sys, os, site modules, print()
import sys
import os


def construct():
    if sys.prefix == sys.base_prefix:
        print("MATRIX STATUS: You are still plugged in")
        print()
        # Stampa l'eseguibile
        print(f"Current python: {sys.executable}")
        print("Virtual environment: None detected")
        print()
        print("WARNING: You're in the global environment!")
        print("The machines can see everything you install.")
        print()
        print("To enter the construct, run:")
        print("python -m venv matrix_env")
        print("and:")
        print("source matrix_env/bin/activate # On Unix")
        print("matrix_env\\Scripts\\activate # On Windows")
        print()
        print("Then run this program again.")
    else:
        path = sys.executable
        path = os.path.dirname(path)
        path = os.path.dirname(path)
        print("MATRIX STATUS: Welcome to the construct")
        # Stampa l'eseguibile
        print(f"Current python: {sys.executable}")
        # Stampa il nome del venv
        print(f"Virtual Environment: {os.path.basename(sys.prefix)}")
        # Stampa il path per arrivare al venv
        print(f"Environment Path: {sys.prefix}")
        print("SUCCESS: You're in an isolated environment!")
        print("Safe to install packages without affecting the global system.")
        print()
        print("Package installation path:")
        # Stampa il path per il package di installazione
        print(path)


if __name__ == "__main__":
    construct()

# python3 -m venv <venv>
# source <venv>/bin/activate
# deactivate
# rm -rf <venv>
