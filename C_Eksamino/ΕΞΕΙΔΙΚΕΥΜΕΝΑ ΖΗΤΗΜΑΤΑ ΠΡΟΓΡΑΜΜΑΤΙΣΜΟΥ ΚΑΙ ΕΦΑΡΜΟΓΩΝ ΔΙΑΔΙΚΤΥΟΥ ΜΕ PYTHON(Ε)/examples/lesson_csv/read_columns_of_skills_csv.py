import csv

with open("Skills.csv", "r", newline="") as scvFile:
    csvData = csv.reader(scvFile)
    for csvLine in csvData:
        print(csvLine[4],"\t",csvLine[1])