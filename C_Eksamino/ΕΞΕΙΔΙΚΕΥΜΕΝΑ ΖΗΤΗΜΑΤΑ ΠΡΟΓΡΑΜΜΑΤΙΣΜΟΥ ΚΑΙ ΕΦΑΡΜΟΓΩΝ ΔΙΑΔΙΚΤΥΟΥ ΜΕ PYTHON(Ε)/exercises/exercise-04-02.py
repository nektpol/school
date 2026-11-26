import csv

with open ("Skills.csv", "r", newline="") as csvFile:
    csvLines = csv.DictReader(csvFile)
    print("Client Info:")
    print("-" * 55)
    for Line in csvLines:
        print(Line["FirstName"], Line["City"])