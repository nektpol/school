import csv

data_list = []

with open("Cars.csv", "r", newline="") as csvFile:
    csvLines = csv.DictReader(csvFile)
    for row in csvLines:
        data_list.append(row)

for row in data_list:
    print(row)
