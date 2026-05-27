import numpy
import pandas
import matplotlib.pyplot as plt
# import requests
# import sys
# import importlib


def loading():
    data = {"Data": numpy.random.rand(1000)}
    # Organizza i dati
    dataFrame = pandas.DataFrame(data)
    # Rende leggibile data frame per plt
    dataFrame.describe()
    # Inizializza l'immagine
    plt.hist(dataFrame["Data"], bins=100)
    # Setta i valori dell'asse y
    plt.ylim(0, 20)
    # Salva l'immagine
    plt.savefig("data.png")


if __name__ == "__main__":
    loading()
