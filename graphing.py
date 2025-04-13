import matplotlib.pyplot as plt
import numpy as np
import os
import platform
import subprocess
from subprocess import Popen, PIPE, check_output

graphingData = []
graphingDataAlt = []

# Open the data.txt written by main program
# Checks the first line for the case, and the type of graph follows
with open ("../data.txt", "r") as file:
    case = file.readline()
    if case == "Genres\n":
        graphCase = "a"
        for line in file:
            graphingData.append(int(line.strip()))

    elif case == "Years\n":
        graphCase = "b"
        for line in file:
            year, occurences = line.strip().split()
            graphingData.append(int(occurences))
            graphingDataAlt.append(int(year))


if graphCase == "a":
    genres = ["Horror", "Romance", "Comedy", "Action", "Adventure", "Animation", "Biography", "Crime", "Drama",
            "Family", "Documentary", "Fantasy", "Game Show", "History", "Musical", "Mystery", "News", "Sci-Fi",
            "Thriller", "Western", "Sports"]

    plt.bar(genres, graphingData)
    plt.ylabel("Occurences")
    plt.title("Genre Frequency")
    plt.savefig("../mygraph.png")
    plt.show()


if graphCase == "b":
    plt.bar(graphingDataAlt, graphingData)
    plt.xlabel("Year")
    plt.ylabel("Occurences")
    plt.title("Year Frequency")
    plt.savefig("../mygraph.png")
    plt.show()