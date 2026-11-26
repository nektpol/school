import csv

cars = [
    {"Brand":"BMW", "Model":"M8", "Year":2019},
    {"Brand":"Honda", "Model":"Civic", "Year":2019},
    {"Brand":"Ford", "Model":"Focus", "Year":2018}
]

with open("Cars.csv", "w", newline="") as csvFile:
    writer = csv.DictWriter(csvFile, fieldnames=cars[0].keys())
    writer.writeheader()
    writer.writerows(cars)

