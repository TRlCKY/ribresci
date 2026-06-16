import numpy
import pandas
import matplotlib.pyplot as plt
from importlib.metadata import version


def loading():
    print("LOADING STATUS: Loading programs...")
    print()
    print("Checking dependencies:")
    if check_dependencies():
        print("Success")
    else:
        print("Failure")
    print()
    print("Analyzing Matrix data...")
    print("Processing 1000 data points...")
    data = {"Data": numpy.random.rand(1000)}
    # Organizza i dati
    dataFrame = pandas.DataFrame(data)
    # Rende leggibile data frame per plt
    dataFrame.describe()
    print("Generating visualization...")
    # Inizializza l'immagine
    plt.hist(dataFrame["Data"], bins=100)
    # Setta i valori dell'asse y
    plt.ylim(0, 20)
    # Salva l'immagine
    plt.savefig("matrix_analysis.png")
    print()
    print("Results saved to: matrix_analysis.png")


def check_dependencies() -> bool:
    with open("requirements.txt") as r:
        lines = r.readlines()
    for line in lines:
        line = line.strip()
        try:
            ver = version(line)
            print(f"[OK] {line} {ver}")
        except Exception as e:
            print(f"Got error: {e}")
            return False
    return True


if __name__ == "__main__":
    loading()

# python3 -m venv <venv>
# source <venv>/bin/activate
# ** PARTE PIP **
# pip install -f requirements.txt
# ** PARTE PIP **
# ** PARTE POETRY ** #
# pip install poetry
# poetry install(prende il toml)
# poetry run python3 loading.py
# ** PARTE POETRY ** #
# deactivate
# rm -rf <venv>
