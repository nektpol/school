import csv

with open("Skills.csv", "r", newline="") as scvFile:
    # csv.reader can take a delimiter parameter, e.g., csv.reader(scvFile, delimiter=';') 
    # if the file uses ";" instead of ","
    # same for csv.writer when writing to a CSV file with a different delimiter
    csvData = csv.reader(scvFile)
    for row in csvData:
        print(row)