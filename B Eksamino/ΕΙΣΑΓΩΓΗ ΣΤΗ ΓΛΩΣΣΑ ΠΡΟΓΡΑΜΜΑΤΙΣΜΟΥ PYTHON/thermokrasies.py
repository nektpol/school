def toCelsius(fahrenheit):
    return (fahrenheit - 32) * 5.0 / 9.0

def doseThermokrasia():
    return int(input("Δώσε Θερμοκρασία σε Fahrenheit: "))

def printThermokrasies():
    print("\n--- Θερμοκρασίες Όλων των Ημερών ---")
    for day, temps in enumerate(AllTempArray, start=1):
        print(f"\nΗμέρα {day}")
        for record, temp in enumerate(temps, start=1):
            print(f"  Μέτρηση {record}: {temp:.2f} °C")
        avg = sum(temps) / len(temps)
        print(f"  Μέση Θερμοκρασία: {avg:.2f} °C")

AllTempArray = []
AvgTempArray = []

for day in range(3):
    TempArray = []
    for record in range(3):
        tempF = doseThermokrasia()
        tempC = toCelsius(tempF)
        print(f"Η θερμοκρασία σε Celsius είναι: {tempC:.2f}")
        TempArray.append(tempC)
    avgTemp = sum(TempArray) / 3
    print(f"Μέση θερμοκρασία για την ημέρα {day+1}: {avgTemp:.2f}")
    AvgTempArray.append(avgTemp)
    AllTempArray.append(TempArray)

printThermokrasies()

print("Η πιο κρύα ημέρα ήταν η ημέρα",
      AvgTempArray.index(min(AvgTempArray)) + 1)
        