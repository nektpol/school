import csv

rows = [["SkillAchieved?","FirstName","Skill","City","ID","LevelAchieved"],
        [1,"John","Python","Athens",123,"Beginner"],
        [0,"Jane","JavaScript","Thessaloniki",456,"Intermediate"],
        [1,"Alice","C++","Patras",789,"Advanced"]]

# "with" statement is used to open the file and ensure it is properly closed after writing
# Append rows to the Skills.csv file
# If I want to replace the rows in the Skills.csv file, I should open it in write mode ("w") instead of append mode ("a").
with open("Skills.csv", "a", newline="") as scvFile:
    csvData = csv.writer(scvFile)
    for row in rows:
        csvData.writerow(row)

