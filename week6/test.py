import csv
import sys

with open("test.csv", "a") as file:
    writer = csv.writer(file)
    writer.writerow(sys.argv[1])