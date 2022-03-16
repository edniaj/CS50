import csv
import sys



with open("test.csv", "a") as file:
    writer = csv.writer(file)
    writer.writerow(sys.argv[1])

with open("hogwarts.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        house = row["House"]
        houses[house] +=1

