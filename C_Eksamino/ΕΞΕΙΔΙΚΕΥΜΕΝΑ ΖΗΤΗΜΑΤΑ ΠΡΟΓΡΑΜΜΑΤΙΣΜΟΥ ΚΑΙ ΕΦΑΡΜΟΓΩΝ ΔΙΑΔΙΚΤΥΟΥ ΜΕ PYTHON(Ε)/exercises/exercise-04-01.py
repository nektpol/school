import csv

rows = [["Tom","Wilson",32,"London"],
        ["Tom","Holland",28,"Hollywood"],
        ["Maria","Smith",31,"Bristol"]]

with open("Clients.csv", "w", newline="") as scvFile:
    csvData = csv.writer(scvFile, delimiter='@')
    for row in rows:
        csvData.writerow(row)

print(f"{'First name':<12}-\t{'Last name':<12}-\t{'Age':<5}-\t{'City':<12}")
print("-" * 55)
with open("Clients.csv", "r", newline="") as scvFile:
    csvData = csv.reader(scvFile, delimiter='@')
    for row in csvData:
        print(f"{row[0]:<12}-\t{row[1]:<12}-\t{row[2]:<5}-\t{row[3]:<12}")

    

