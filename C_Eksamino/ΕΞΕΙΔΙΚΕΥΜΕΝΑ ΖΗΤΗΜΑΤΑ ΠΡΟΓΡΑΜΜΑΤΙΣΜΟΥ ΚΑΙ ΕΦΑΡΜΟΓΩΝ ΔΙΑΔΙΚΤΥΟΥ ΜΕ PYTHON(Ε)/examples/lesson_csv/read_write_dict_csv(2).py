import csv

car = {"Brand":"Tesla", "Model":"Model 3", "Year":2022}

with open("Cars.csv", "a", newline="") as csvFile:
    writer = csv.DictWriter(csvFile, fieldnames=car.keys())
    writer = csv.writer(csvFile)
    writer.writerow(car.values())