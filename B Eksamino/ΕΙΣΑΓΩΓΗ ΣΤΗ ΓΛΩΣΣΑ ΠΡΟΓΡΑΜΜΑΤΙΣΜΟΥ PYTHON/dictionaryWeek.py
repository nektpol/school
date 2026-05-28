dict = {}

def doseTimi():
    return int(input("Δώσε τιμή από 1 ως 7: "))

def addDay(key, num):
    global dict
    match num:
        case 1:
            dict[key] = "Δευτέρα"
        case 2:
            dict[key] = "Τρίτη"
        case 3:
            dict[key] = "Τετάρτη"
        case 4:
            dict[key] = "Πέμπτη"
        case 5:
            dict[key] = "Παρασκευή"
        case 6:
            dict[key] = "Σάββατο"
        case 7:
            dict[key] = "Κυριακή"
            


for i in range(10):
    while True:
        dayNumber = doseTimi()
        if 1 <= dayNumber <= 7:
            addDay(i, dayNumber)
            break
        else:
            print("Λάθος αριθμός, παρακαλώ εισάγετε έναν αριθμό από 1 έως 7.")

print("Dictionary:", dict)
